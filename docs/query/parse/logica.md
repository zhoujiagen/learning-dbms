# Logica

> https://logica.dev/
>
> Logica is an open source declarative logic programming language for data manipulation.

## Syntax

文法:

> docs/syntax.md

``` bnf
// 程序
// Program is a sequence of entries separated by semicolon.
program ::= program_entry (';' program_entry)* [;]

// 每个项是导入、规则或函子应用
// Each entry is an import, a rule, or a functor application.
program_entry ::= import | rule | functor_application

// 导入
// Example of an import -- import path.to.file.Predicate as AnotherPredicate
import ::=
  'import' dot_separated_path '.' logica_predicate ['as' logica_predicate]
dot_separated_path ::= [^<newline>]+

// 谓词: 以大写字母开始, 或以@开始(命令式谓词)
// Predicate defined by the program is alphanumeric starting with an
// uppercase letter, or '@' if it is an imperative predicate.
logica_predicate ::= ordinary_logica_predicate | imperative_predicate
// Ordinary predicates is what Logica is mostly about, example -- Grandparent
ordinary_logica_predicate ::= [A-Z_][0-9a-zA-Z_]*
// Imperative predicates are used for annotations, example -- @Ground
imperative_predicate ::= '@' [0-9a-zA-Z_]*

// 数据库表作为谓词
// You can also use database tables as predicates.
predicate ::= logica_predicate | '`'[^`]+'`' | [A-Za-z_0-9.]+

// 变量
// Variable must be lowercase numeric.
variable ::= [a-z0-9_]

// 规则: 规则头 :- 规则体
// Rule is a head with an optional body.
rule ::= rule_head [ ':-' rule_body ]

// 规则体: 命题
// Body of the rule is a proposition.
rule_body ::= proposition

// 规则头: 调用, 可选的赋值和可选的distinct标记
// Head of a rule is a call with an optional assignment and
// an optional 'distinct' denotation.
rule_head ::= head_call [assignment] ['distinct']

// 赋值: 简单赋值, 聚合赋值
// Example of a simple assignment is -- = 2 * x
// and example of an aggregating assignment is -- List= 2 * x.
assignment ::= simple_assignment | aggregating_assignment
simple_assignment ::= '=' expression
aggregating_operator ::= ('+' | logica_predicate) '='
aggregating_assignment ::= aggregating_operator expression

// 调用: 记录谓词, 聚合记录谓词
// No space is allowed between predicate name and the opening
// parenthesis.
call ::= predicate '(' record_internal ')'
head_call ::= logica_predicate '(' aggregating_record_internal ')'

// 记录: 记录字段值
// Example of record_internal -- a: 5, b: 2 * x
record_field_value ::= field ':' expression
record_internal ::=
  [record_field_value (',' record_field_value)* [',' '..' variable]] |
  ('..' variable)

// 聚合记录: 聚合字段值
// Example of aggregating_field_value -- x? += 5
aggregating_field_value ::= field '?' aggregating_assignment
aggregating_record_internal  ::=
  [record_field_value | aggregating_field_value]
  [',' (record_field_value | aggregating_field_value)]*

// 表达式: 谓词调用、操作、组合、列表包含、蕴含或对象描述
// Expression is a predicate call, operation, combine,
// list inclusion, implication or an object description.
expression ::=
  call |
  unary_operator_call |
  binary_operator_call |
  combine |
  inclusion |
  implication |
  string_literal |
  number_literal |
  boolean_literal |
  null_literal |
  list |
  record |
  ('(' expression ')')

// 操作符
operator ::= '+'|'-'|'/'|'>'|'<'|'<='|'>='|'=='|'->'|'&&'|'||'

// 一元操作符
unary_operator ::= '!'|'-'

// 操作符调用: 一元、二元
unary_operator_call ::= unary_operator expression
binary_operator_call ::= expression operator expression

// 列表包含
// Example of inclusion -- x in [1,2,3,4]
inclusion ::= expression 'in' expression

// 蕴含
// Example of an implication -- if a == b then 7 else 9
implication ::=
  '(' 'if' expression then expression
  ['else if' expression 'then' expression]*
  'else' expression ')'

// 组合
// If combine has a body then it must be enclosed in parenthesis.
combine ::= 'combine' aggregating_assignment [':-' rule_body]

// 具体对象描述
// Concrete object specification.
string_literal ::= '"'[^"<newline>]'"'
number_literal ::= [0-9]+ [ '.'[0-9]+ ]
boolean_literal ::= 'true'|'false'
null_literal ::= 'null'
list ::= '[' [expression [','expression]*] ']'
record ::= '{' record_internal '}'

// 命题: 交、并、否、谓词调用、操作或列表包含
// Proposition is a conjunction, disjunction, negation,
// a predicate call, operation, or list inclusion.
proposition ::=
  conjunction |
  disjunction |
  negation |
  call |
  binary_operator_call |
  unary_operator_call |
  assign_combination |
  inclusion |
  ('(' proposition ')')

// 交
conjunction ::= proposition (',' proposition)*
// 并
disjunction ::= proposition ('|' proposition)*
// 否
negation ::= '~' proposition

// 组合赋值
// Example of assign combination -- l List= (2 * x :- x in [1,2,3])
assign_combination ::= variable
  aggregating_assignment |
  (aggregating_operator '(' expression ':-' proposition ')')

// 函子应用
// Example of a functor application -- F := G(A: B)
functor_application ::= logica_predicate ':=' logica_predicate '(' functor_record_internal ')'
functor_record_internal ::=
  [logica_predicate ':' logica_predicate]
  (',' logica_predicate ':' logica_predicate )*
```

- Comments(注释)

A symbol `#` occurring outside of a string starts a comment that goes to the end of the line. A combination `/*` occurring anywhere outside a string starts a comment that goes to the first occurence of `/*`.


- 支持的函数

`common/data/processed_functions.py`.

## Example

### PostgreSQL

Setup PostgreSQL:

> colab_logica.py PostgresJumpStart

```
$ uname -a
Linux DESKTOP-V3GKSFN 4.19.128-microsoft-standard #1 SMP Tue Jun 23 12:58:10 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux

$ sudo apt-get -y -qq install postgresql
$ sudo service postgresql start

$ sudo -u postgres psql -c "CREATE USER zhoujiagen WITH SUPERUSER"
CREATE ROLE
$ sudo -u postgres psql -c "ALTER USER zhoujiagen PASSWORD 'zhoujiagen';"
ALTER ROLE
$ sudo -u postgres psql -U postgres -c 'CREATE DATABASE zhoujiagen;'
CREATE DATABASE
```

Query with facts:

```
# file: postgres-facts.l

@Engine("psql");

# create table datas(n int);
# insert into datas values(1),(2) returning *;
Data(n:) :- datas(n:);

# create table datas2(n1 int, n2 int);
# insert into datas2 values (1,1),(1,2),(1,3),(2,1) returning *;

@OrderBy(Count, "counts desc");
@Limit(Count, 2);
Count(n1:, counts? += 1) distinct :-
  datas2(n1:, n2:);
```

```
$ logica postgres-facts.l run Data
 n
---
 1
 2
(2 rows)

$ logica postgres-facts.l run Count
 n1 | counts
----+--------
  1 |      3
  2 |      1
(2 rows)
```

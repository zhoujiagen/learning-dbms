# 事务操作

## Methods

sql/transaction.h:

``` c++
bool trans_check_state(THD *thd);
void trans_reset_one_shot_chistics(THD *thd);
void trans_track_end_trx(THD *thd);

// 显式开启事务
bool trans_begin(THD *thd, uint flags= 0);
// 提交事务
bool trans_commit(THD *thd);
// 隐式提交事务
bool trans_commit_implicit(THD *thd);
// 回滚事务
bool trans_rollback(THD *thd);
// 隐式回滚事务
bool trans_rollback_implicit(THD *thd);

bool trans_commit_stmt(THD *thd);
bool trans_rollback_stmt(THD *thd);
bool trans_commit_attachable(THD *thd);

// 设置保存点
bool trans_savepoint(THD *thd, LEX_STRING name);
bool trans_rollback_to_savepoint(THD *thd, LEX_STRING name);
bool trans_release_savepoint(THD *thd, LEX_STRING name);
```

storage/innobase/handler/ha_innodb.cc:

``` c++
// 打开InnoDB数据库
static int innobase_init(void	*p)
```

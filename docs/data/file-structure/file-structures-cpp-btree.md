### 9. Multi-level Indexing and B-trees

#### 9.1 Introduction: The Invention of the B-Tree

- R. Bayer, E. McCreight, Organization and Maintenance of Large Ordered Indexes, 1972.
- Douglas Comer, The Ubiquitous B-Tree, 1979.

#### 9.2 Statement of the Problem

- searching the index must be faster than binary searching
- insertion and deletion must be as fast as search

#### 9.3 Indexing with Binary Search Trees

##### 9.3.1 AVL Trees

- G. M. Adel'son-Vel'skii, E. M. Landis
- HB(k): permitted to be k levels out of balance.
- height-balanced 1-tree, HB(1) tree: no two subtrees of any root differ by more than one level.

##### 9.3.2 Paged Binary Trees
##### 9.3.3 Problems with Paged Trees

#### 9.4 Multilevel Indexing, a Better Approach to Tree Indexes
#### 9.5 B-trees: Working up from the Bottom

B-trees are multilevel indexes that solve the problem of linear cost of insertion and deletion:

- each node of a B-tree is an index record,
- each of these records has the same maximum number of key-reference pairs, called the **order** of the B-Tree,
- the records also have a minimum number of key-references pairs, typically half of the order.

#### 9.6 Example of Creating a B-Tree

Example: key sequence, insertion

```
CSDTAMPIBWNGURKEHOLJYQZFXV

```

Insert C:

<div>
{% dot Insert_C.svg
digraph Insert_C {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P0>C||||"];
}
%}
</div>

Insert S:

<div>
{% dot Insert_S.svg
digraph Insert_S {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P0>C|<P1>S|||"];
}
%}
</div>

Insert D:

<div>
{% dot Insert_D.svg
digraph Insert_D {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P0>C|<P2>D|<P1>S||"];
}
%}
</div>

Insert T:

<div>
{% dot Insert_T.svg
digraph Insert_T {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P0>C|<P2>D|<P1>S|<P3>T|"];
}
%}
</div>

Insert A:

<div>
{% dot Insert_A.svg
digraph Insert_A {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>T|||"];
L2_P110[shape=record, label="<P4>A|<P0>C|<P2>D||"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P1>S|<P3>T|||"];
root:P86 -> L2_P86;
}
%}
</div>

Insert M:

<div>
{% dot Insert_M.svg
digraph Insert_M {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>T|||"];
L2_P110[shape=record, label="<P4>A|<P0>C|<P2>D||"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P5>M|<P1>S|<P3>T||"];
root:P86 -> L2_P86;
}
%}
</div>

Insert P:

<div>
{% dot Insert_P.svg
digraph Insert_P {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>T|||"];
L2_P110[shape=record, label="<P4>A|<P0>C|<P2>D||"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P5>M|<P6>P|<P1>S|<P3>T|"];
root:P86 -> L2_P86;
}
%}
</div>

Insert I:

<div>
{% dot Insert_I.svg
digraph Insert_I {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>P|<P134>T||"];
L2_P110[shape=record, label="<P4>A|<P0>C|<P2>D||"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P7>I|<P5>M|<P6>P||"];
root:P86 -> L2_P86;
L2_P134[shape=record, label="<P1>S|<P3>T|||"];
root:P134 -> L2_P134;
}
%}
</div>

Insert B:

<div>
{% dot Insert_B.svg
digraph Insert_B {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>P|<P134>T||"];
L2_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P7>I|<P5>M|<P6>P||"];
root:P86 -> L2_P86;
L2_P134[shape=record, label="<P1>S|<P3>T|||"];
root:P134 -> L2_P134;
}
%}
</div>

Insert W:

<div>
{% dot Insert_W.svg
digraph Insert_W {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>P|<P134>W||"];
L2_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P7>I|<P5>M|<P6>P||"];
root:P86 -> L2_P86;
L2_P134[shape=record, label="<P1>S|<P3>T|<P9>W||"];
root:P134 -> L2_P134;
}
%}
</div>

Insert N:

<div>
{% dot Insert_N.svg
digraph Insert_N {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>P|<P134>W||"];
L2_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P7>I|<P5>M|<P10>N|<P6>P|"];
root:P86 -> L2_P86;
L2_P134[shape=record, label="<P1>S|<P3>T|<P9>W||"];
root:P134 -> L2_P134;
}
%}
</div>

Insert G:

<div>
{% dot Insert_G.svg
digraph Insert_G {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>M|<P158>P|<P134>W|"];
L2_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P11>G|<P7>I|<P5>M||"];
root:P86 -> L2_P86;
L2_P158[shape=record, label="<P10>N|<P6>P|||"];
root:P158 -> L2_P158;
L2_P134[shape=record, label="<P1>S|<P3>T|<P9>W||"];
root:P134 -> L2_P134;
}
%}
</div>

Insert U:

<div>
{% dot Insert_U.svg
digraph Insert_U {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P110>D|<P86>M|<P158>P|<P134>W|"];
L2_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
root:P110 -> L2_P110;
L2_P86[shape=record, label="<P11>G|<P7>I|<P5>M||"];
root:P86 -> L2_P86;
L2_P158[shape=record, label="<P10>N|<P6>P|||"];
root:P158 -> L2_P158;
L2_P134[shape=record, label="<P1>S|<P3>T|<P12>U|<P9>W|"];
root:P134 -> L2_P134;
}
%}
</div>

Insert R:

<div>
{% dot Insert_R.svg
digraph Insert_R {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>W|||"];
L2_P230[shape=record, label="<P110>D|<P86>M|<P158>P||"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P11>G|<P7>I|<P5>M||"];
L2_P230:P86 -> L3_P86;
L3_P158[shape=record, label="<P10>N|<P6>P|||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>W|||"];
L3_P134[shape=record, label="<P13>R|<P1>S|<P3>T||"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert K:

<div>
{% dot Insert_K.svg
digraph Insert_K {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>W|||"];
L2_P230[shape=record, label="<P110>D|<P86>M|<P158>P||"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P11>G|<P7>I|<P14>K|<P5>M|"];
L2_P230:P86 -> L3_P86;
L3_P158[shape=record, label="<P10>N|<P6>P|||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>W|||"];
L3_P134[shape=record, label="<P13>R|<P1>S|<P3>T||"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert E:

<div>
{% dot Insert_E.svg
digraph Insert_E {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>W|||"];
L2_P230[shape=record, label="<P110>D|<P86>I|<P254>M|<P158>P|"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P11>G|<P7>I||"];
L2_P230:P86 -> L3_P86;
L3_P254[shape=record, label="<P14>K|<P5>M|||"];
L2_P230:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P6>P|||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>W|||"];
L3_P134[shape=record, label="<P13>R|<P1>S|<P3>T||"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert H:

<div>
{% dot Insert_H.svg
digraph Insert_H {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>W|||"];
L2_P230[shape=record, label="<P110>D|<P86>I|<P254>M|<P158>P|"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P11>G|<P16>H|<P7>I|"];
L2_P230:P86 -> L3_P86;
L3_P254[shape=record, label="<P14>K|<P5>M|||"];
L2_P230:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P6>P|||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>W|||"];
L3_P134[shape=record, label="<P13>R|<P1>S|<P3>T||"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert O:

<div>
{% dot Insert_O.svg
digraph Insert_O {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>W|||"];
L2_P230[shape=record, label="<P110>D|<P86>I|<P254>M|<P158>P|"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P11>G|<P16>H|<P7>I|"];
L2_P230:P86 -> L3_P86;
L3_P254[shape=record, label="<P14>K|<P5>M|||"];
L2_P230:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>W|||"];
L3_P134[shape=record, label="<P13>R|<P1>S|<P3>T||"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert L:

<div>
{% dot Insert_L.svg
digraph Insert_L {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>W|||"];
L2_P230[shape=record, label="<P110>D|<P86>I|<P254>M|<P158>P|"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P11>G|<P16>H|<P7>I|"];
L2_P230:P86 -> L3_P86;
L3_P254[shape=record, label="<P14>K|<P18>L|<P5>M||"];
L2_P230:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>W|||"];
L3_P134[shape=record, label="<P13>R|<P1>S|<P3>T||"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert J:

<div>
{% dot Insert_J.svg
digraph Insert_J {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>W|||"];
L2_P230[shape=record, label="<P110>D|<P86>I|<P254>M|<P158>P|"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P11>G|<P16>H|<P7>I|"];
L2_P230:P86 -> L3_P86;
L3_P254[shape=record, label="<P19>J|<P14>K|<P18>L|<P5>M|"];
L2_P230:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>W|||"];
L3_P134[shape=record, label="<P13>R|<P1>S|<P3>T||"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert Y:

<div>
{% dot Insert_Y.svg
digraph Insert_Y {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>Y|||"];
L2_P230[shape=record, label="<P110>D|<P86>I|<P254>M|<P158>P|"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P11>G|<P16>H|<P7>I|"];
L2_P230:P86 -> L3_P86;
L3_P254[shape=record, label="<P19>J|<P14>K|<P18>L|<P5>M|"];
L2_P230:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>Y|||"];
L3_P134[shape=record, label="<P13>R|<P1>S|<P3>T||"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|<P20>Y||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert Q:

<div>
{% dot Insert_Q.svg
digraph Insert_Q {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>Y|||"];
L2_P230[shape=record, label="<P110>D|<P86>I|<P254>M|<P158>P|"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P11>G|<P16>H|<P7>I|"];
L2_P230:P86 -> L3_P86;
L3_P254[shape=record, label="<P19>J|<P14>K|<P18>L|<P5>M|"];
L2_P230:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>Y|||"];
L3_P134[shape=record, label="<P21>Q|<P13>R|<P1>S|<P3>T|"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|<P20>Y||"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert Z:

<div>
{% dot Insert_Z.svg
digraph Insert_Z {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>P|<P206>Z|||"];
L2_P230[shape=record, label="<P110>D|<P86>I|<P254>M|<P158>P|"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P11>G|<P16>H|<P7>I|"];
L2_P230:P86 -> L3_P86;
L3_P254[shape=record, label="<P19>J|<P14>K|<P18>L|<P5>M|"];
L2_P230:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P230:P158 -> L3_P158;
root:P230 -> L2_P230;
L2_P206[shape=record, label="<P134>T|<P182>Z|||"];
L3_P134[shape=record, label="<P21>Q|<P13>R|<P1>S|<P3>T|"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|<P20>Y|<P22>Z|"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert F:

<div>
{% dot Insert_F.svg
digraph Insert_F {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>I|<P302>P|<P206>Z||"];
L2_P230[shape=record, label="<P110>D|<P86>G|<P278>I||"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P23>F|<P11>G||"];
L2_P230:P86 -> L3_P86;
L3_P278[shape=record, label="<P16>H|<P7>I|||"];
L2_P230:P278 -> L3_P278;
root:P230 -> L2_P230;
L2_P302[shape=record, label="<P254>M|<P158>P|||"];
L3_P254[shape=record, label="<P19>J|<P14>K|<P18>L|<P5>M|"];
L2_P302:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P302:P158 -> L3_P158;
root:P302 -> L2_P302;
L2_P206[shape=record, label="<P134>T|<P182>Z|||"];
L3_P134[shape=record, label="<P21>Q|<P13>R|<P1>S|<P3>T|"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|<P20>Y|<P22>Z|"];
L2_P206:P182 -> L3_P182;
root:P206 -> L2_P206;
}
%}
</div>

Insert X:

<div>
{% dot Insert_X.svg
digraph Insert_X {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>I|<P302>P|<P206>Z||"];
L2_P230[shape=record, label="<P110>D|<P86>G|<P278>I||"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P23>F|<P11>G||"];
L2_P230:P86 -> L3_P86;
L3_P278[shape=record, label="<P16>H|<P7>I|||"];
L2_P230:P278 -> L3_P278;
root:P230 -> L2_P230;
L2_P302[shape=record, label="<P254>M|<P158>P|||"];
L3_P254[shape=record, label="<P19>J|<P14>K|<P18>L|<P5>M|"];
L2_P302:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P302:P158 -> L3_P158;
root:P302 -> L2_P302;
L2_P206[shape=record, label="<P134>T|<P182>X|<P326>Z||"];
L3_P134[shape=record, label="<P21>Q|<P13>R|<P1>S|<P3>T|"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P9>W|<P24>X||"];
L2_P206:P182 -> L3_P182;
L3_P326[shape=record, label="<P20>Y|<P22>Z|||"];
L2_P206:P326 -> L3_P326;
root:P206 -> L2_P206;
}
%}
</div>

Insert V:

<div>
{% dot Insert_V.svg
digraph Insert_V {
        splines=line;
        node[shape = record, width = 1, height = 0.1];
        root[shape=record, label="<P230>I|<P302>P|<P206>Z||"];
L2_P230[shape=record, label="<P110>D|<P86>G|<P278>I||"];
L3_P110[shape=record, label="<P4>A|<P8>B|<P0>C|<P2>D|"];
L2_P230:P110 -> L3_P110;
L3_P86[shape=record, label="<P15>E|<P23>F|<P11>G||"];
L2_P230:P86 -> L3_P86;
L3_P278[shape=record, label="<P16>H|<P7>I|||"];
L2_P230:P278 -> L3_P278;
root:P230 -> L2_P230;
L2_P302[shape=record, label="<P254>M|<P158>P|||"];
L3_P254[shape=record, label="<P19>J|<P14>K|<P18>L|<P5>M|"];
L2_P302:P254 -> L3_P254;
L3_P158[shape=record, label="<P10>N|<P17>O|<P6>P||"];
L2_P302:P158 -> L3_P158;
root:P302 -> L2_P302;
L2_P206[shape=record, label="<P134>T|<P182>X|<P326>Z||"];
L3_P134[shape=record, label="<P21>Q|<P13>R|<P1>S|<P3>T|"];
L2_P206:P134 -> L3_P134;
L3_P182[shape=record, label="<P12>U|<P25>V|<P9>W|<P24>X|"];
L2_P206:P182 -> L3_P182;
L3_P326[shape=record, label="<P20>Y|<P22>Z|||"];
L2_P206:P326 -> L3_P326;
root:P206 -> L2_P206;
}
%}
</div>

#### 9.7 An Object-Oriented Representation of B-Trees

##### 9.7.1 Class `BTreeNode`: representing B-Tree Nodes in Memory
##### 9.7.2 Class `BTree`: Supporting Files of B-Tree Nodes

#### 9.8 B-Tree Methods Search, Insert, and Others

##### 9.8.1 Searching
##### 9.8.2 Insertion
##### 9.8.3 Create, Open, and Close
##### 9.8.4 Testing the B-Tree

#### 9.9 B-Tree Nomenclature

In this book, we use the term **B+ tree** to refer to a complex situation in which the data file is not entry sequenced but is organized into a linked list of sorted blocks of records.

#### 9.10 Formal Definition of B-Tree Properties

the properties of a B-tree of order $m$:

- every page has a maximum of $m$ descendants,
- every page, except for the root and the leaves, has at least $\left \lceil m/2 \right \rceil$ descendants,
- the root has at least two descendants(unless it is a leaf),
- all the leaves appear on the same level,
- the leaf level forms a complete, ordered index of the associated data file.

#### 9.11 Worst-Case Search Depth

Given:

- number of keys: $N$
- order of B-tree

Quesetion: in the worst case, what wiil be the maximum number of disk access required to located a key in the tree?

level $l$, minimum number of descendants:

- $l=1$: $2$
- $l=2$: $2 \times \lceil m/2 \rceil$
- $l=3$: $2 \times \lceil m/2 \rceil^2$
- ...
- $l=d$: $2 \times \lceil m/2 \rceil^{d-1}$

$$
N \ge 2 \times \lceil m/2 \rceil^{d-1} \\
d \le 1 + \texttt{log}_{\lceil m/2 \rceil}(N/2)
$$

Example: $N=100 0000, m=512$, $d \le 3.37$.

#### 9.12 Deletion, Merging, and Redistribution

rules for deleting a key `k` from a node `n` in a B-tree:

1. if `n` has more than a minimum number of keys and `k` is not the largest in `n`, simply delete `k` from `n`;

2. if `n` has more than the minimum number of keys and `k` is the largest in `n`, delete `k` and modify the higher level indexes to reflect the new largest key in `n`;

3. if `n` has exactly the minimum number of keys and one of the sliblings of `n` has **few enough keys**, **merge** `n` with its sibling and **delete** a key from the parent node;

4. if `n` has eaxctly the minimum number of keys and one of the siblings of `n` has **extra keys**, **redistribute** by moving some keys from a sibling to `n`, and modify the higher level indexes to reflect the new largest keys in the affected nodes.

##### 9.12.1 Redistribution

redistribution differs from both splitting and merging:

- it never causes the collection of nodes in the tree to change,
- and there is no necessary, fxied prescription for how the keys should be rearranged.

#### 9.13 Redistribution During Insertion: A Way to Improve Storage Utilization

redistribution during insertion is a way of avoiding, or at least postponing, the creation of new pages.

#### 9.14 B* Trees

B*-tree: extend the notion of redistribution during insertion to include new rules for splitting

- every page has a maximum of $m$ descendants,
- every page except for the root has at least $\lceil (2m-1)/3 \rceil$ descendants,
- the root has at least two descendants(unless it is a leaf),
- all the leaves appear on the same level.

#### 9.15 Buffering of Pages: Virtual B-Trees

stating that we cannot hold **all** of an index in memory does not imply that we cannot hold **some** of it there.

page buffer: hold some number of B-tree pages,

virtual B-tree: if the page is not in the memory, then we read it into the buffer from secondary storage, replacing one of the pages that was previously there.

##### 9.15.1 LRU Replacement

page fault: acessing the disk to bring in a page that is not already in the buffer

- we have never used the page,
- it was once in the buffer, but has since been replaced with a new page.

LRU replacement:

- assumption: **temporal locality**, we are more likely to need a page that we have used recently than we are to need a page that we have never used or on that we uses some time age. in B-tree, accessing a set of sibling pages involves repeated access to the parent page in rapid succession.

- keep track of the requests for page, the page to be replaced is the one that has gone the longest time without a request for use.

##### 9.15.2 Replacement Based on Page Height

always retain the pages that occur at the highest levels of the tree

##### 9.15.3 Importance of Virtual B-Trees

#### 9.16 Variable-Length Records and Keys

a key varies in length

### 10. Indexed Sequential File Access and Prefix B+ trees

#### 10.1 Indexed Sequential Access

indexed sequential files structures provides two alternative views of a file:

- indexed: the file can be seen as a set of records that is indexed by key;
- sequential: the file can be accessed sequentially, returning records in order by key.

#### 10.2 Maintaining a Sequence Set

##### 10.2.1 The Use of Blocks
##### 10.2.2 Choice of Block Size

#### 10.3 Adding a Simple Index to the Sequence Set
#### 10.4 The Content of the Index: Separators Instead of Keys
#### 10.5 The Simple Prefix B+ Tree
#### 10.6 Simple Prefix B+ Tree Maintenance

##### 10.6.1 Changes Localized to Single Blocks in the Sequence Set
##### 10.6.2 Changes Involving Multiple Blocks in the Sequence Set

#### 10.7 Index Set Block Size
#### 10.8 Internal Structure of Index Set Blocks: A Variable-Order B-Tree
#### 10.9 Loading a Simple Prefix B+ Tree
#### 10.10 B+ Tree
#### 10.11 B-Trees, B+ Trees, and Simple Prefix B+ Trees in Perspective

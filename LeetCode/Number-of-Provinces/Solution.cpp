/**

Example 1:

isConnected = [[1,1,0],[1,1,0],[0,0,1]]

 CITY |0 1 2
------|------
     0|1 1 0 
     1|1 1 0
     2|0 0 1


Connections:
0 ► 1
1 ► 0
2 ► none


Example 2:

isConnected = [[1,0,0],[0,1,0],[0,0,1]]

 |0 1 2
-|------
0|1 0 0 
1|0 1 0
2|0 0 1


Connections:
0 ► none
1 ► none
2 ► none


Example 3: 

 |0 1 2 3
---------
0|1 1 0 0 
1|1 1 1 0
2|0 1 1 1
3|0 0 1 1


0 ► 1
1 ► 0 2
2 ► 1 3
3 ► 2

**/
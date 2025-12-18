# Problem Statement

Build a software tool which can be used as both a command shell and also an interpreter for LAMDA language, which takes large matrices of size millions cross millions and does operations to it. The operations range from simple matrix addition to complex algorithms like Gauss Elimination and row reduction and Linear Algebraic analysis like finding the basis of row space and column space of the given matrix.

# High Level Solution Approach For Core Architecture (Prototype)

1. there should be an algorithm to verify given CLI arguments and decide whether to interpret input files or open shell
1. an algorithm to verify validity of names of given files as CLI arguments if it should work as an **interpreter**
	1. display error message signifying the problem found if invalid arguments are given
		1. return control to OS
	1. else handle the control to the `loop()` function
		1. compute according to the commands interpreted from the target file
		1. display error message signifying problems found while interpreting if there are any syntax errors or logical errors
		1. return control to the `main()` function
		1. return control to the OS
1. print tool details, and handle control to `loop()` function if it has to be used as a **command shell**
	1. compute according to the commands given
	1. signify any errors in commands
	1. execute the command and cleanup for new command untill `exit` command is recieved
	1. when exit command is recieved, return control to OS

### High Level Flow Chart

```text
						(start)
						   ↓
			+---T-----<argc > 2>-----F---+
			↓							 ↓
	  +------------+					 O
	 /output error/		{decide bwn shell & interpreter}
	+------------+				Y			   X
			↓					↓			   ↓		
			+←------------------+			   O
			|						  {setup environment}	 
			|								   X			 
			|								   |←------------+
			|								   O			 ↑
			|						{read, parse & execute}  |
			|                                  X			 |
		 	↓		 +---------+			   ↓			 |
 (end)------+←-------|freeRAM()|←----T---<exit loop ?>---F--→+
					 +---------+
 ```

### Flow Chart for "decide bwn **shell** & **interpreter**"

```text
					   O
					   ↓
			  +-----------------+
			  |*inputLoc = NULL |
			  +-----------------+
					   ↓
		+←-----T--<argc = 1>--F-----→+
		|							 ↓
		↓					+------------------+
 +----------------+			|inputLoc = argv[2]|
 |inputLoc = stdin|			+------------------+
 +----------------+					 ↓
		↓					  <inputLoc = NULL>
   +-----------------+		  |				  |
  / output aboutTool/		  F				  T
 +-----------------+		  |				  |
		↓					  ↓ 			  ↓
		+------------→+←------+			+-------------+
					  |				   / output error/
					  |				  +-------------+
					  ↓						  ↓
					  X						  Y
```

### Flow Chart for "**setup environment**"

```text
					O
					|						// Structure of MATRIX
					↓						//		**matrix
		+------------------------+			//		name(0..20)
		| declare matList(0..1)  |			//		metadata(0..20)
		| default matrices O & I |			//		properties (no.of rows,
	 	+------------------------+			//					no.of columns,
					↓						//					trace,
		+------------------------+			//					determinant,
		| declare cmdStrng(0..50)|			//					complexe elements,
		+------------------------+			//					singularity)
					↓						// End of structure
	     +----------------------+			// Structure of OPDATA 
		 | OPDATA operationData |			//		linecount
		 +----------------------+			//		pastCMD(0..10)
					|						// End of Structre
					↓
					X
```

### Flow Chart for "**Read, Parse & Execute**"

Before knowing the Read, Parse, & Execution flow charts, this is how we decompesed the tool functionally in designing phases

1. User can declare a matrix with the following syntax
```

```text

```



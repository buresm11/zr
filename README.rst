ZR
=======

Compiler of zr language using LLVM. 

Get up
===============

Requirement
-----------
* cmake version >= 3.5
* llvm 3.7.0

| ``clone repository``  
| ``mkdir build``  
| ``cmake ..``  
| ``make``  

Running
===============

``zr [-o|-n] [-v|-s] filename``

* [-o|-n]  -o optimize, -n no optimization
* [-v|-s]  -v verbose, -s silent

Syntax
===============

Variables
------------

.. code-block:: c

	int a;
	bool b; 

Built-In functions
------------------

* **print(object)** - prints object
* **scan()** - reads a value from user and returns it

.. code-block:: c

	int i;
	i = 5;
	print(i);

	i = scan();


Operations
----------

* int supports: + , - , * , / , == , != , >= , <= , < , >
* bool supports: || , && , == , !=, !

Condition
------------

.. code-block:: c

	if x == y-1 do
		call();
	else if x == y+1 do
		call();
	else if x == y do
		call();
	else do
		call();
	end

Cycle
------------

.. code-block:: c

	while i < n do
		i=i+1;
	end

Functions declaration
------------

.. code-block:: c

	def int func(int a, int c)
		return 0;
	end

Example
----------

**Factorial:** 

.. code-block:: c

def int f(int x)
	if x == 0 do
		return 1;
	else do
		return x * f(x-1);
	end
end

def void fact(int ix)
	int i;
	i = 0;
	while i < ix do
		print(f(i));
		i = i+1;
	end
end


def int main()
	int x;
	x = scan();
	fact(x);
end

Optimalizations
----------

* Tail call elimination
* Function inlining
* Constant propagation
* Dead code elimination
* Dead instruction elimination
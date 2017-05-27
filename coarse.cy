y[int]
x[int, real<4>, string]

# func is a function with multiple inputs and a multi-type output, Cython's function calls are call by value
[int, char<5>] func X[int], Y[char<2>], R[real]:
	Z = ~Z * (!Y - R)
	Z = a[i]
	Y = b[i+3]
	X = 1 + func(z)
	z[int] = 5
	func(a,b)
	return Y, Z
	return
	break
	continue

# This code is just for testing your cython compiler
@ As you know, this
is a multi-line comment
which must be implemented @

# start and finish functions, They don't have any input and outputs
start main
finish exit

# a global variable
Q[int, char]

# func is a function with multiple inputs and a multi-type output, Cython's function calls are call by value
[int, char] func X[int], Y[char], R[real]:
	X = X*2
	write(Y)
	Y = 'x'
	R = R - 0.01 * 1.23 - 0.66
	write(R)
	Z[int, char]
	Z[0,1] = X, Y
	return Z

# notice that exit is the name of the function, it's not a label, Cython does not support labels
exit:
	# after finishing main, this function must be executed
	write("This code executed successfully\n")
	# exit does not have any return value, finishing this line will terminate the program like return 0 in C's main function
	return 

# also main is the name of the function
main:
	# As main is the start function, execution starts from this point

	# Testing reading and writing from standard input, output
	X[int] = 10
	write(X)
	X = 12
	write(X)
	read(X)
	write(X)

	# an array
	Y[int<100>]



	# simple if statement
	@ grammar does not support this now, to fix this suppose that grammar is like:
		<EXPR> ::= id['['<EXPR>']'] @
	if (Y[0] + Y[1]) > 12 :
		z = x + write("if condition is true\n")
	elif (Y[0] + Y[1]) > 6 :
		write("if other condition is true\n")
	elif (Y[0] + Y[1]) > 3 :
		write("if other condition is true\n")
	else:
		write("if condition if false\n")

	Ch[char] 
	read(Ch)

	# case statement, notice indents
	case Ch:
		'a':
			write("given character is \'a\'\n")
		'b':
			write("given character is \'b\'\n")
		default: 
			write("given character is not \'a\'\n")

	# simple function call
	Q = func(X, Ch, 12.3)
	# Cython's function calls are call by value, so X must save its value 
	write(X)
	write(Q[0])
	write(Q[1])

	# main does not have any return value, when code reaches this line, finish function must be called
	return		

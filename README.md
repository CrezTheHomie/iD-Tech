# iD-Tech

# How To Self-Debug

Follow these steps before putting up your question flag to figure out your issues!

1. Check your error message. On the left side of your coding space, there will be a red x if there is an error. Read the message and see if you can understand it.
2. Semicolons! If it doesn't need a curly bracket (ex. If statements, loops, classes), it needs a semicolon. Make sure that you have them all.
3. Has your variable been created? If you are getting an error saying “variableName cannot be resolved to a variable”, you might not have created your variable yet. Make sure that the variable has been created.
4. Is your variable in scope? You could have created the variable, but because it's in a different set of curly braces, it can't be used. Make your variable in a location that all places can use it.
5. Do you have the right amount of curly braces? If you have too little or too much, your program will throw an error. You can test this by highlighting each starting curly brace. Its matching closing brace will then be outlined in a rectangular box. If no rectangular box shows up anywhere in your program, you have too little. If you have one left over after you highlight all your starting braces, you have too much.
6. Are your curly braces opening after the start of your method and closing at the end of the method’s code? Make sure your follow the format:
<return type> <function name> (<variables>){
	//your code here
}
Example:
int add(int firstNumber, int secondNumber){
	//your code here
}
7. Did you include all the things you need? You often need to import your iostream and string libraries and if you create any custom headers, you'll need to include them too.
8. If your if statement is erroring or if it isn't acting how you expected, check how you wrote it. Remember, if statements need a double equals sign (==) instead of a single one. Also, talk through your if check. Sometimes, it turns out that what you put in your if statement isn't what you meant to happen.
9. If your program is compiling but not acting the way you think it should, follow your code from start up till when the error occurred.
10. Did you check Game Plan? Game Plan has a lot of helpful knowledge resources in there. Go check it and see if it solves your problem.
11. Did you ask a neighbor? One of your neighbors might have the answer you're looking for! Ask them and see if they know.

# After iD Tech

If you want to get started/get better with graphics:
https://www.sfml-dev.org/tutorials/2.4/
https://www.youtube.com/watch?v=axIgxBQVBg0

If you want to understand more complex data management:

# Arrays and multidimensional arrays 

(http://www.cplusplus.com/doc/tutorial/arrays/)

	Arrays are like buckets to put things in. They are insanely useful being able to do things like manage inventory 
and refer to specific points on a map. 

# Stacks

need #include <stack> (http://www.cplusplus.com/reference/stack/stack/?kw=stack)

	Stacks are quite literally putting data "on top of" other data. You can only access the bottom piece of the stack
after you have taken off the pieces on top of it.

# Queues

need #include <queue> (http://www.cplusplus.com/reference/queue/queue/?kw=queue)

	Queues are just like rollercoaster lines. The first person to get into the line is also the firsrt person to get out of the line
and get on to the rollercoaster. 

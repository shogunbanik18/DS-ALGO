# # '''

# # Welcome to GDB Online.
# # GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
# # C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
# # Code, Compile, Run and Debug online from anywhere in world.

# # '''
# # print ('Hello World')

name ="Shogun"
age =21

is_adult=True


name ="Tony Stark"
age=51
print(name + " is genius")

name=input("What is Your Name ? ")
print("Hello "+name)

number=18
print(float(18))

age =input("Enter your old age : ")
new_age=float(age)+2
print(new_age)

first =input("Enter first Number : ")
second =input("Enter Second Number : ")

sum =int(first)+int(second)
print("The sum is "+str(sum))

strings
methods
name ="Tony Stark"
print(name.upper())
print(name)

print(name.find("s"))
print(name.replace("S","M"))
print(name)

name ="Tony Stark"
print('Stark' in name)

print(5**2)
i=5
i+=2
print(i)

result =2+3*5
print(result)

print(3==3)

print(not 2>3)
age=18
if(age>=19):
    print("You are and Adult")
    print("You can vote")
elif(age<=18):
    print("You are underage")
print("Thank You!")

# mini project 
# calculator 
first=int(input("Enter first Number : "))
operator =input("enter operator(+,-,*,/%):")
second =int(input("Enter second number : "))

if operator=="+":
    print(first+second)
elif operator=="-":
    print(first-second)
elif operator=="*":
    print(first*second)
elif operator=="/":
    print(first/second)
elif operator=="%":
    print(first%second)
else:
    print("Invalid Operation")
    
    
numbers=range(5)
print(numbers)

i=1
while i<=5:
    print(i*"*")
    i=i+1
    
j=5
while j>=0:
    print(j*"#")
    j-=1

range(5)

for loop 
for i in range(5):
    print(i+1)
    
list data types 
marks =[95,98,97]
print(marks[1:3])

for score in marks:
    print(score)
    
marks.append(99)
marks.insert(0,99)
print(marks)
print(99 in marks)
print(len(marks))

i=0
while i<len(marks):
    print(marks[i])
    i+=1
    
marks.clear()
print(marks)

break and continue in Python
students=["Ram","Shyam","Kishan","Radha","Radhika"]
for student in students:
    if student=="Kishan":
        continue;
    print(student)

tuple like list
tuples are immutable
marks =(95,98,97,97,97)
marks[0]=99
print(marks.count(97))
print(marks.index(97))

[] : lists
() : tuple 
{} : set


set
marks={95,96,97,97,97}
print(len(marks))

for score in marks:
    print(score)
print(marks)

person ="ram","shyam","abhi"
print(person)


# dictionary 
# like hashmap

# marks ={"english":95,"chemistry":98}
# information ={"ram":"balllu"}

# print(marks["chemistry"])
# marks["physics"]=97
# print(marks)

# marks["physics"]=100
# print(marks)

# Functions 
# in-built Functions
# module functions (related variables and related functions in one file)
# user defined functions 

# module 
# import math 
# from math import sqrt
# print(sqrt(15))
# # print(dir(math))

# from math import *

# user defined functions 
# def function_name(para):
    # blaahhh blaahhh blaahhh

def printsum(a,b=4):
    print(a+b)

# a=int(input("Enter 1st No : "))
# b=int(input("Enter 2nd No : "))
printsum(1)


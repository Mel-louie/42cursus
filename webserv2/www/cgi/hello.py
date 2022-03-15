#!usr/bin/python
import os
# import sys

# print ("Content-type:text/html\r\n\r\n")
print ('<html>')
print ('<head>')
print ('<title>Hello World - First CGI Program</title>')
print ('</head>')
print ('<body>')

for i, j in os.environ.items():
    print(i, j)

print(os.environ.keys())

print ('<h2>Hello World! This is my first CGI program</h2>')
print ('<h2>Hello World! This is my first CGI program</h2>')
print ('<h2>Hello World! This is my first CGI program</h2>')
print ('<h2>Hello World! This is my first CGI program</h2>')
print ('<h2>Hello World! This is my first CGI program</h2>')
print ('<h2>Hello World! This is my first CGI program</h2>')


print ('</body>')
print ('</html>')

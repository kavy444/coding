def calculator(a,b,c):
    s=0
    if c=="+":
        s=a+b
    elif c=="-":
        s=a-b
    elif c=="/":
        s=a/b
    elif c=="*":
        s=a*b
    else:
        s="invalid choice" 
    return s               

h=calculator(6,7,"+")
print(h)
import matplotlib.pyplot as plt
import math

sample = range(-1000,1001) # For ak calculation
sample2 = range(-2,3) # For x2 calculation
sample10 = range(-10,11) # For x10 calculation
sample100 = range(-100,101) # For x100 calculation
karray = [] # ak values for k

def valueforak(k): # Closed form formula after solving Integral for ak
    if (k == 0):
        return 2.0/5
    else:
        return math.sin((2.0*k*math.pi)/5.0)/(k*math.pi)

def xreal(t): # Original Periodic Function
  if(abs(t-((int(t)/10)*10)<=2 or abs(t-(int(t)/10)*10)>=8)):
    return 1
  return 0


def x2real(t): # Value using Fourier Series for x2 real
    ans = 0
    for k in sample2:
        ans += valueforak(k)*math.cos(k*(math.pi/5)*t)
    return ans

def x2complex(t): # Value using Fourier Series for x2 complex
    ans = 0
    for k in sample2:
        ans += valueforak(k)*math.sin(k*(math.pi/5)*t)
    return ans

def x10real(t): # Value using Fourier Series for x10 real
    ans = 0
    for k in sample10:
        ans += valueforak(k)*math.cos(k*(math.pi/5)*t)
    return ans

def x10complex(t): # Value using Fourier Series for x10 complex
    ans = 0
    for k in sample10:
        ans += valueforak(k)*math.sin(k*(math.pi/5)*t)
    return ans

def x100real(t): # Value using Fourier Series for x100 real
    ans = 0
    for k in sample100:
        ans += valueforak(k)*math.cos(k*(math.pi/5)*t)
    return ans

def x100complex(t): # Value using Fourier Series for x100 complex
    ans = 0
    for k in sample100:
        ans += valueforak(k)*math.sin(k*(math.pi/5)*t)
    return ans

def error2(t): # Value using Error Formula for x2
  return abs(x2real(t)-xreal(t))

def error10(t): # Value using Error Formula for x10
  return abs(x10real(t)-xreal(t))

def error100(t): # Value using Error Formula for x100
  return abs(x100real(t)-xreal(t))


for k in sample:
    karray.append(valueforak(k))
plt.title("ak(y axis) vs k(x axis)")
plt.plot(sample, karray)
plt.show()

time = []
px2real = []
px2complex = []
px10real = [] 
px10complex = [] 
px100real = []
px100complex = []
px = []
perror2 = [] 
perror10 = []
perror100 = []

t = -100.0
while(t <= 100.0):
    px.append(xreal(t))
    px2real.append(x2real(t))
    px2complex.append(x2complex(t))
    px10real.append(x10real(t))
    px10complex.append(x10complex(t))
    px100real.append(x100real(t))
    px100complex.append(x100complex(t))
    perror2.append(error2(t))
    perror10.append(error10(t))
    perror100.append(error100(t))
    time.append(t)
    t += 0.05

#Plotting Graphs
plt.plot(time,px)
plt.title("x(t) Real Part")
plt.show()

plt.plot(time,px2real)
plt.title("x2(t) Real Part")
plt.show()

plt.plot(time,px2complex)
plt.title("x2(t) Imaginary Part")
plt.show()

plt.plot(time,px10real)
plt.title("x10(t) Real Part")
plt.show()

plt.plot(time,px10complex)
plt.title("x10(t) Complex Part")
plt.show()

plt.plot(time,px100real)
plt.title("x100(t) Real Part")
plt.show()

plt.plot(time,px100complex)
plt.title("x100(t) Complex Part")
plt.show()

plt.plot(time,perror2)
plt.title("error2(t) ")
plt.show()

plt.plot(time,perror10)
plt.title("error10(t) ")
plt.show()

plt.plot(time,perror100)
plt.title("error100(t) ")
plt.show()


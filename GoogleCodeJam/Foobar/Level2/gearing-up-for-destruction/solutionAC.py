from fractions import Fraction  
 
def answer(pegs):
    arrLength = len(pegs)
    if ((not pegs) or arrLength == 1):
        return [-1,-1]
 
    even = True if (arrLength % 2 == 0) else False
    sum = (- pegs[0] + pegs[arrLength - 1]) if even else (- pegs[0] - pegs[arrLength -1])

    # print sum
 
    if (arrLength > 2):
        for index in xrange(1, arrLength-1):
            sum += 2 * (-1)**(index+1) * pegs[index]
 
    # print sum
    FirstGearRadius = Fraction(2 * (float(sum)/3 if even else sum)).limit_denominator()
    print(FirstGearRadius)
 
 
    currentRadius = FirstGearRadius
    for index in xrange(0, arrLength-2):
        CenterDistance = pegs[index+1] - pegs[index]
        NextRadius = CenterDistance - currentRadius
        if (currentRadius < 1 or NextRadius < 1):
            return [-1,-1]
        else:
            currentRadius = NextRadius
 
    return [FirstGearRadius.numerator, FirstGearRadius.denominator]

if __name__ == "__main__":
  l = map(int,raw_input().split())
  print(answer(l))
  # print answer([4, 9, 17, 31, 40])
  # print answer([4,30,50])

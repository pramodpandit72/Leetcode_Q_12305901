import random

for n in range(8):
   OUT = "["

   for i in range(10 ** 4):
       OUT += str(random.randrange(0 if n > 1 else 1, ((n+1) * 2) ** 2)) + ','

   print(OUT[:-1] + "]")
total = 0


class Adder:
    def __init__(self):
        self.total = 0

    def add(self, i):
        self.total += i

adder = Adder()

for i in range(100000000):
    adder.add(i)

print adder.total

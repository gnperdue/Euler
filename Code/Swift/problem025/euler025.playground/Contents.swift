class Fibo {
  var fibolist = [1]

  func addFiboNumber() {
    let l = self.fibolist.count
    if 0 == l {
      self.fibolist = [1]
    } else if 1 == l {
      self.fibolist = [1, 1]
    } else {
      self.fibolist.append(self.fibolist[l - 1] + self.fibolist[l - 2])
    }
  }

  func getFiboNumber(_ index: Int) -> Int? {
    self.fibolist[index]
  }
}

func countDigits(inNumber n: Int) -> Int {
  var m = n
  var count = 0
  while (m > 0) {
    count += 1
    m /= 10
  }
  return count
}

let fibo = Fibo()
var index = 0
var val = fibo.getFiboNumber(index)!
var ndigits = countDigits(inNumber: val)

while ndigits < 3 {
  index += 1
  fibo.addFiboNumber()
  val = fibo.getFiboNumber(index)!
  ndigits = countDigits(inNumber: val)
}

print(val)
print(index + 1)
print(ndigits)

print(UInt64.max)


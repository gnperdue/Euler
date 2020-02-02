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

let fibo = Fibo()
var index = 0
let max = 4000000
var val = fibo.getFiboNumber(index)!

while val < max {
  fibo.addFiboNumber()
  index += 1
  val = fibo.getFiboNumber(index)!
}

var output = fibo.fibolist.filter{ $0 % 2 == 0 }.reduce(0, +)
print(output)

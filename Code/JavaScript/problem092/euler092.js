var sums = [];
var n89  = 0;

function euler092(max) {
  var min  = 0;

  var numberOfWorkers = 4;
  var searchBin       = Math.floor(max / numberOfWorkers);

  if (searchBin * numberOfWorkers != max) {
    alert("Number of workers times bin size does not cover the full range!");
  }

  for (var i = 0; i < numberOfWorkers; i++) {
    var localMin = min + searchBin * i + 1;
    var localMax = min + searchBin * (i + 1);
    console.log("Worker " + i + " search min = " + localMin + ", search max = " + localMax);
    var worker = new Worker("worker.js");
    worker.postMessage([localMin,localMax]);
    worker.onmessage = eulerSum;
  }

  // how to join workers?
  // while (sums.length != numberOfWorkers) {}

  // for (i = 0; i < numberOfWorkers; i++) {
  //   n89 += sums[i];
  // }

  console.log("Initializing html element...");
  var answer = document.getElementById("euleranswer");
  answer.innerHTML = n89;
  console.log("Initialized html element...");
}

function eulerSum(event) {
  console.log("Worker Sum = " + event.data);
  // sums.push_back(event.data);
  n89 += event.data;
  var answer = document.getElementById("euleranswer");
  answer.innerHTML = n89;
}

window.onload = euler092(8);


importScripts("workerlib.js");

onmessage = function(event) {
  minmax = event.data;
  console.log("Worker got data " + minmax);
  var n89 = computeN89(minmax[0],minmax[1]);
  console.log("  Worker sum for data " + minmax + " is " + n89);
  postMessage(n89); 
};

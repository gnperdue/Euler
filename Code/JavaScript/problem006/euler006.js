
function euler006(max) {
  var ans = squareOfSum(max) - sumOfSquares(max);
  var answer = document.getElementById("euleranswer");
  answer.innerHTML = ans;
}

function sumOfSquares(n) {
  var sos = 0;
  for (var i = 1; i <= n; i++) sos += i*i;
  return sos;
}

function squareOfSum(n) {
  var sos = 0;
  for (var i = 1; i <= n; i++) sos += i;
  return sos*sos;
}

window.onload = euler006(100);

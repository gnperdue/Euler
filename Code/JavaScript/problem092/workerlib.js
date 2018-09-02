
// we will take on faith that every reductive iteration ends in 1 or 89 and
// not look for repeated numbers in the iteration chain and check that the
// repeated number is 89 
function computeN89(min,max) {
  console.log("Calling computeN89 for (" + min + "," + max + ")");
  var n89 = 0;
  for (var i = min; i <= max; i++) {
    var digsum = i;
    for (;;) {
      digsum = getDigitSqSum(digsum);
      if (  0 === digsum) break;
      if (  1  == digsum) break;
      if ( 89  == digsum) { n89++; break; }
    }
  }
  console.log("Returning sum for (" + min + "," + max + ") = " + n89);
  return n89;
}

function getDigitSqSum(num) {
  console.log("Calling getDigitSqSum for " + num);
  var sum      = 0;
  var digit    = num % 10;
  var newdigit = Math.floor(num/10);
  console.log("   digit = " + digit + ", newdigit = " + newdigit);
  sum += digit * digit;
  console.log("   sum = " + sum);
  while (0 !== newdigit) {
    digit    = sum % 10;
    newdigit = Math.floor(num/10);
    sum += digit * digit;
  }
  console.log("   final sum = " + sum);
  return sum;
}

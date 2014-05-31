function collatzLength(start) {
    var collatz = {
        "start": start,
        "leng": 0
    };
    if (start > 0) {
        collatz.leng = 1;
        while (start > 1) {
            if (start % 2 === 0) {
                collatz.leng += 1;
                start = start / 2;
            } else {
                collatz.leng += 1;
                start = 3 * start + 1;
            }
        }
    }
    return collatz;
}

function max(current, next) {
    if (current.leng > next.leng) return current;
    return next;
}



function euler014() {

    var numVals = 200;
    var i = 0;
    var nums = [];
    for (i = 0; i < numVals; i++) {
        nums.push(i + 1);
    }
    var cols = nums.map(collatzLength);
    var longest = cols.reduce(max);
    console.log("The longest Collatz:");
    console.log(longest.start);
    console.log(longest.leng);

    var answer = document.getElementById("euleranswer");
    answer.innerHTML = longest.leng;

    var w = (cols.length < 600) ? 600 : cols.length;
    var h = w;
    var svg = d3.select("body").append("svg");
    svg.attr({
        width: w,
        height: h
    });

    var color_scale = d3.scale.linear();
    color_scale.domain([0, longest.leng]);
    color_scale.range([0, 255]);

    var length_scale = d3.scale.linear();
    length_scale.domain([0, longest.leng]);
    length_scale.range([0, w]);

    svg.selectAll("rect").data(cols).enter().append("rect")
        .attr("x", function(d, i) {
            return i;
        })
        .attr("y", 0)
        .attr("width", 1)
        .attr("height", function(d) {
            return length_scale(d.leng);
        })
        .attr("fill", function(d) {
            return "rgb(0, 0, " + Math.floor(color_scale(d.leng)) + ")";
        });

}
window.onload = euler014;

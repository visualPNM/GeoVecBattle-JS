function abs(x) { //절댓값 구하기
  if(x >= 0) { return x; }
  else { return -x; }
}

function prime(x) { // 333 이하의 소수 판정하기
  var a;
  var prime = 1;
  for(a = 2; (a < 18 && a < x); a++)
  {
    if(x % a == 0)
    {
      prime = 0;
      break;
    }
  }
  if(x<2){ prime = 0; }
  return prime;
}

var specA = [0, 0, 0, 0, 0]; // spec : 0(hit point), 1(att), 2(def), 3(critical/normal), 4(probability of critical)
var specB = [0, 0, 0, 0, 0];
var length = new Array(2); // length of a, b
var unitA = [];
var unitB = [];
var turn;
var damage;
var random;
var speed;
var real_speed;
var sosu;
var nameA;
var nameB;

nameA = '김철수'; //수정가능
nameB = '이영희'; //수정가능
speed = 5; //수정가능

length[0] = nameA.length;
length[1] = nameB.length;

for (var i = 0; i < nameA.length; ++i) {
  var ucode = nameA.charCodeAt(i);
  if (ucode <= 127) {
    unitA = unitA.concat([ucode]);
  }
  else {
    unitA = unitA.concat([ucode & 0xff, ucode / 256 >>> 0]);
  }
}

for (var i = 0; i < nameB.length; ++i) {
  var ucode = nameB.charCodeAt(i);
  if (ucode <= 127) {
    unitB = unitB.concat([ucode]);
  }
  else {
    unitB = unitB.concat([ucode & 0xff, ucode / 256 >>> 0]);
  }
}
//speed
if(speed == 0) { real_speed = 2000; }
else if(speed == 1) { real_speed = 1500; }
else if(speed == 2) { real_speed = 1000; }
else if(speed == 3) { real_speed = 750; }
else if(speed == 4) { real_speed = 600; }
else if(speed == 5) { real_speed = 450; }
else if(speed == 6) { real_speed = 333; }
else if(speed == 7) { real_speed = 250; }
else if(speed == 8) { real_speed = 167; }
else if(speed == 9) { real_speed = 100; }
else { real_speed = 750; }

// turn
if(unitA > unitB) { turn = 1; }
else if(unitA < unitB) { turn = 0; }

for(i = 0; unitA[i] == unitB[i]; i++)
{
  if(unitA[i+1] > unitB[i+1]) { turn = 1; }
  else if(unitA[i+1] < unitB[i+1]) { turn = 0; }
}

for(var i = 0; i < nameA.length; i++) // character 1
  {
    if(unitA[i] !== ' ') {
      specA[0] += abs(unitA[i]);
      specA[1] += 2*abs(unitA[i]);
      specA[2] *= abs(unitA[i]);
      specA[2] += abs(unitA[i]) + 7;
      specA[3] *= abs(unitA[i]);
      specA[3] += 2*abs(unitA[i]) + 7;
      specA[4] += abs(unitA[i])*abs(unitA[i]);
        
      specA[0] = 100 + specA[0] % 234;
      specA[1] = 10 + specA[1] % 24;
      specA[2] = specA[2] % 333;
      specA[3] = specA[1] * (specA[3] % 3 + 3);
      specA[4] = 3 + specA[4] % 31;
    }
}

for(var i = 0; i < nameB.length; i++) // character 1
  {
    if(unitB[i] !== ' ') {
      specB[0] += abs(unitB[i]);
      specB[1] += 2*abs(unitB[i]);
      specB[2] *= abs(unitB[i]);
      specB[2] += abs(unitB[i]) + 7;
      specB[3] *= abs(unitB[i]);
      specB[3] += 2*abs(unitB[i]) + 7;
      specB[4] += abs(unitB[i])*abs(unitB[i]);
        
      specB[0] = 100 + specB[0] % 234;
      specB[1] = 10 + specB[1] % 24;
      specB[2] = specB[2] % 333;
      specB[3] = specB[1] * (specB[3] % 3 + 3);
      specB[4] = 3 + specB[4] % 31;
    }
}

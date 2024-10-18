// Author: reDragonCoder

//If ... Else
Console.ForegroundColor=ConsoleColor.Blue;
Console.WriteLine("---- If...Else Examples ----");
Console.ResetColor();

//Example 1
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 1");
Console.ResetColor();
if(20>18){
    Console.WriteLine("20 is greater than 18");
}
Console.WriteLine();

//Example 2
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 2");
Console.ResetColor();
int x=20;
int y=18;
if(x>y){
    Console.WriteLine("x is greater than y");
}
Console.WriteLine();

//Example 3
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 3");
Console.ResetColor();
int time=20;
if(time<18){
    Console.WriteLine("Good day.");
}else{
    Console.WriteLine("Good evening.");
}
Console.WriteLine();

//Example 4
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 4");
Console.ResetColor();
time=22;
if(time<10){
    Console.WriteLine("Good morning.");
}else if(time<20){
    Console.WriteLine("Good day.");
}else{
    Console.WriteLine("Good evening.");
}
Console.WriteLine();

//Example 5
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 5");
Console.ResetColor();
time=20;
string result=(time<18) ? "Good day." : "Good evening.";
Console.WriteLine(result);
Console.WriteLine();

Console.WriteLine();
//**********************************************************

//Switch
Console.ForegroundColor=ConsoleColor.Blue;
Console.WriteLine("---- Switch ----");
Console.ResetColor();

//Example 1
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 1");
Console.ResetColor();
int day=4;
switch(day){
    case 1:
        Console.WriteLine("Monday");
        break;
    case 2:
        Console.WriteLine("Tuesday");
        break;
    case 3:
        Console.WriteLine("Tuesday");
        break;
    case 4:
        Console.WriteLine("Wednesday");
        break;
    case 5:
        Console.WriteLine("Thursday");
        break;
    case 6:
        Console.WriteLine("Friday");
        break;
    case 7:
        Console.WriteLine("Saturday");
        break;
    case 8:
        Console.WriteLine("Sunday");
        break;
}
Console.WriteLine();

//Example 2
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 2");
Console.ResetColor();
day=4;
switch(day) {
  case 6:
    Console.WriteLine("Today is Saturday.");
    break;
  case 7:
    Console.WriteLine("Today is Sunday.");
    break;
  default:
    Console.WriteLine("Looking forward to the Weekend.");
    break;
}
Console.WriteLine();

Console.WriteLine();
//**********************************************************

//While Loop
Console.ForegroundColor=ConsoleColor.Blue;
Console.WriteLine("---- While Loop ----");
Console.ResetColor();

//Example 1
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 1");
Console.ResetColor();
int i=0;
while(i<5){
    Console.WriteLine(i);
    i++;
}
Console.WriteLine();

//Example 2
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 2");
Console.ResetColor();
i=0;
do{
    Console.WriteLine(i);
    i++;
}while(i<5);
Console.WriteLine();

Console.WriteLine();
//**********************************************************

//For Loop
Console.ForegroundColor=ConsoleColor.Blue;
Console.WriteLine("---- For Loop ----");
Console.ResetColor();

//Example 1
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 1");
Console.ResetColor();
for(i=0; i<5; i++){
    Console.WriteLine(i);
}
Console.WriteLine();

//Example 2
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 2");
Console.ResetColor();
for(i=0; i<=10; i=i+2){
    Console.WriteLine(i);
}
Console.WriteLine();

//Example 3
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 3");
Console.ResetColor();
for(i=1; i<=2; ++i){
    Console.WriteLine("Outer: "+i);
    for(int j=0; j<=3; j++){
        Console.WriteLine("Inner: "+j);
    }
}
Console.WriteLine();

Console.WriteLine();
//**********************************************************

//Foreach Loop
Console.ForegroundColor=ConsoleColor.Blue;
Console.WriteLine("---- Foreach Lopp ----");
Console.ResetColor();

//Example 1
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 1");
Console.ResetColor();
string[] cars={"Volvo", "BMW", "Ford", "Mazda"};
foreach(string k in cars){
    Console.WriteLine(i);
}
Console.WriteLine();

Console.WriteLine();
//**********************************************************

//Break & Continue
Console.ForegroundColor=ConsoleColor.Blue;
Console.WriteLine("---- Break & Continue ----");
Console.ResetColor();

//Example 1 - Break
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 1");
Console.ResetColor();
for(i=0; i<10; i++){
    if(i==4){
        break;
    }
    Console.WriteLine(i);
}
Console.WriteLine();

//Example 2 - Continue
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 2");
Console.ResetColor();
for(i=0; i<10; i++){
    if(i==4){
        continue;
    }
    Console.WriteLine(i);
}
Console.WriteLine();

//Example 3 - Break in While loop
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 3");
Console.ResetColor();
i=0;
while(i<10){
    Console.WriteLine(i);
    i++;
    if(i==4){
        break;
    }
}
Console.WriteLine();

//Example 4 - Continue in While loop
Console.ForegroundColor=ConsoleColor.Green;
Console.WriteLine("Example 4");
Console.ResetColor();
i=0;
while(i<10){
    if(i==4){
        i++;
        continue;
    }
    Console.WriteLine(i);
    i++;
}
Console.WriteLine();

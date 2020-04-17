 void calculator (int num1, int num2, char operator1)
 {
    int answer;
    if (operator1 == '+')
    {
        answer = num1 + num2;
        cout << num1 << " + " << num2 << " = " << answer;
    }
    if (operator1 == '-')
    {
        answer = num1 - num2;
        cout << num1 << " - " << num2 << " = " << answer;
    }
    if (operator1 == '*')
    {
        answer = num1 * num2;
        cout << num1 << " * " << num2 << " = " << answer;
    }
    if (operator1 == '/')
    {
        answer = num1 / num2;
        cout << num1 << " / " << num2 << " = " << answer;
    }
    if (operator1 != '+' && operator1 != '-' && operator1 != '*' && operator1 != '/') 
    {
        cout << "Invalid operator!";
    }
    
 }
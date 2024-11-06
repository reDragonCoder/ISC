// Author: reDragonCoder

using System;

// We define the IMessenger interface
interface IMessenger{
    void SendMessage(string message);
}

// Base class for messengers
class MessengerBase:IMessenger{
    public virtual void SendMessage(string message){
        Console.WriteLine("Sending generic message: "+message);
    }
}

// Derived class for email messaging
class EmailMessenger:MessengerBase{
    public override void SendMessage(string message){
        Console.WriteLine("Sending message by email: "+message);
    }
}

// Derived class for SMS messaging
class SmsMessenger:MessengerBase{
    public override void SendMessage(string message){
        Console.WriteLine("Sending message by SMS: "+message);
    }
}

// Main program
class Program{
    static void Main(){
        IMessenger email=new EmailMessenger();
        IMessenger sms=new SmsMessenger();

        email.SendMessage("Hello from email!");
        sms.SendMessage("Hello from SMS!");
    }
}


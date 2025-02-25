using System;

namespace RomanNumber.Models
{
    public class RomanNumberException : Exception
    {
        public RomanNumberException() { }
        public RomanNumberException(string message) : base(message) { }
        public RomanNumberException(string message, Exception inner) : base(message, inner) { }
    }
}

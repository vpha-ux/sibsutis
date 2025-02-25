namespace RomanNumber.Models
{
    public class RomanNumber : ICloneable, IComparable
    {
        private ushort _number;

        private static readonly Dictionary<int, string> RomanNums = new Dictionary<int, string>() {
            { 1,    "I"},
            { 5,    "V"},
            { 10,   "X"},
            { 50,   "L"},
            { 100,  "C"},
            { 500,  "D"},
            { 1000, "M"}
        };

        private RomanNumber(ushort n)
        {
            if (n is < 1 or > 3999)
            {
                throw new RomanNumberException("Cannot express number as a Roman Numeral");
            }
            this._number = n;
        }

        public static RomanNumber Add(RomanNumber? n1, RomanNumber? n2)
        {
            return n1 + n2;
        }

        public static RomanNumber operator+(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 is null || n2 is null || n1._number + n2._number > 3999)
            {
                throw new RomanNumberException("Invalid operator");
            }

            n1._number += n2._number;
            return n1;
        }

        public static RomanNumber Sub(RomanNumber? n1, RomanNumber? n2)
        {
            return n1 - n2;
        }

        public static RomanNumber operator-(RomanNumber? n1, RomanNumber? n2)
        {
            
            if (n1 is null || n2 is null || n1._number - n2._number < 1)
            {
                throw new RomanNumberException("Invalid operator");
            }

            n1._number -= n2._number;
            return n1;
        }
        
        public static RomanNumber Mul(RomanNumber? n1, RomanNumber? n2)
        {
            return n1 * n2;
        }

        public static RomanNumber operator*(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 is null || n2 is null || n1._number * n2._number > 3999)
            {
                throw new RomanNumberException("Invalid operator");
            }

            n1._number *= n2._number;
            return n1;
        }

        public static RomanNumber Div(RomanNumber? n1, RomanNumber? n2)
        {
            return n1 / n2;
        }

        public static RomanNumber operator/(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 is null || n2 is null || n1._number / n2._number < 1)
            {
                throw new RomanNumberException("Invalid operator");
            }
            
            n1._number *= n2._number;
            return n1;
        }
 
        public override string ToString()
        {
            string input = this._number.ToString();
            string res = "";
            int powerOf10 = (int)Math.Floor(Math.Log10(this._number));
            for (int i = 0; i <= powerOf10; i++)
            {
                Console.WriteLine(input[i]);
                if ((input[i] - '0') % 5 == 4)
                {
                    res += RomanNums[(int)Math.Pow(10, powerOf10 - i)];
                    res += RomanNums[((input[i] - '0') == 4 ? 5 : 10) * (int)Math.Pow(10, powerOf10 - i)];
                    continue;
                }

                if ((input[i] - '0') > 4)
                {
                    res += RomanNums[5 * (int)Math.Pow(10, powerOf10 - i)];
                }
                for (int j = 0; j < (input[i] - '0') % 5; j++)
                {
                    res += RomanNums[(int)Math.Pow(10, powerOf10 - i)];
                }
            }
            return res;
        }

        public object Clone()
        {
            return new RomanNumber(this._number);
        }

        public int CompareTo(object? obj)
        {
            if (obj is RomanNumber romanNumber)
            {
                return this._number - romanNumber._number;
            }

            throw new RomanNumberException("Cannot compare to not Roman Numeral");
        }
    }
}

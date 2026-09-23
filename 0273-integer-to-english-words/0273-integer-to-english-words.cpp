class Solution {
public:
    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen",
        "Nineteen"
    };

    vector<string> multens = {
        "", "Ten", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string underThousand(int num) {
        string res = "";

        if (num >= 100) {
            res += below20[num / 100] + " Hundred";
            num = num % 100;

            if (num > 0) {
                res += " ";
            }
        }

        if (num >= 20) {
            res += multens[num / 10];

            if (num % 10 != 0) {
                res += " " + below20[num % 10];
            }
        } else {
            res += below20[num];
        }

        return res;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string res = "";

        int billion = num / 1000000000;
        num %= 1000000000;

        int million = num / 1000000;
        num %= 1000000;

        int thousand = num / 1000;
        num %= 1000;

        if (billion > 0) {
            res += underThousand(billion) + " Billion ";
        }
        if (million > 0) {
            res += underThousand(million) + " Million ";
        } if (thousand > 0) {
            res += underThousand(thousand) + " Thousand ";
        } if (num > 0) {
            res += underThousand(num);
        }

        if (res[res.size() - 1] == ' ') return res.substr(0, res.size() - 1);
        return res.substr(0, res.size());
    }
};
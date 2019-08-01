class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
                        "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        int billion = 1000000000, million = 1000000, thousand = 1000, hundred = 100, twenty = 20;

        if (num >= billion) {
            int first = num / billion;
            int second = num % billion;
            return numberToWords(first) + " Billion" + ((second == 0) ? "" : (" " + numberToWords(second)));
        }

        if (num >= million) {
            int first = num / million;
            int second = num % million;
            return numberToWords(first) + " Million" + ((second == 0) ? "" : (" " + numberToWords(second)));
        }

        if (num >= thousand) {
            int first = num / thousand;
            int second = num % thousand;
            return numberToWords(first) + " Thousand" + ((second == 0) ? "" : (" " + numberToWords(second)));
        }

        if (num >= hundred) {
            int first = num / hundred;
            int second = num % hundred;
            return numberToWords(first) + " Hundred" + ((second == 0) ? "" : (" " + numberToWords(second)));
        }

        if (num < hundred && num >= 20) {
            return tens[num / 10 - 2] + ((num % 10 == 0) ? "" : (" " + ones[num % 10]));
        }

        return ones[num];
    }
};

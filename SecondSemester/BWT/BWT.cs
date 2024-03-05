using Microsoft.VisualBasic;

public class BWT
{
    public static Tuple<string, int> BWTransform(string inputString)
    {
        var suffixArray = new int[inputString.Length];
        for (int i = 0; i < inputString.Length; i++)
        {
            suffixArray[i] = i;
        }

        Array.Sort(suffixArray, (x, y) => BWT.CompareSubstrings(inputString, x, y));

        var bwtResult = new char[inputString.Length];
        for (int i = 0; i < inputString.Length; i++)
        {
            bwtResult[i] = (suffixArray[i] > 0) ? inputString[suffixArray[i] - 1] : inputString[^1];
        }

        int endPosition = Array.IndexOf(suffixArray, 0);

        return Tuple.Create(new string(bwtResult), endPosition);
    }

    public static string InverseBWTransform(string bwtString, int endPosition)
    {
        var countDictionary = new Dictionary<char, int>();
        var firstCountArray = new int[bwtString.Length];

        for (int i = 0; i < bwtString.Length; i++)
        {
            if (countDictionary.TryGetValue(bwtString[i], out var count))
            {
                countDictionary[bwtString[i]] = count + 1;
            }
            else
            {
                countDictionary[bwtString[i]] = 1;
            }
            firstCountArray[i] = count;
        }

        int countSmaller = 0;
        var secondCountDictionary = new Dictionary<char, int>();

        foreach (var kvp in countDictionary.OrderBy(entry => entry.Key))
        {
            countSmaller += kvp.Value;
            secondCountDictionary[kvp.Key] = countSmaller - kvp.Value;
        }

        var result = new char[bwtString.Length];
        int index = endPosition;

        for (int i = bwtString.Length - 1; i >= 0; i--)
        {
            result[i] = bwtString[index];
            index = firstCountArray[index] + (countDictionary.TryGetValue(bwtString[index], out var count) ? 
                secondCountDictionary[bwtString[index]] : 0);
        }

        return new string(result);
    }
    static int CompareSubstrings(string str, int index1, int index2)
    {
        string substring1 = $"{str[index1..]}{str[..index1]}";
        string substring2 = $"{str[index2..]}{str[..index2]}";

        return String.Compare(substring1, substring2);
    }
}
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
        var countArray = new int[256];
        var firstCountArray = new int[bwtString.Length];
        for (int i = 0; i < bwtString.Length; i++)
        {
            firstCountArray[i] = countArray[bwtString[i]]++;
        }

        int countSmaller = 0;
        var secondCountArray = new int[256];
        for (int i = 0; i < secondCountArray.Length; i++)
        {
            countSmaller += countArray[i];
            secondCountArray[i] = countSmaller - countArray[i];
        }

        var result = new char[bwtString.Length];
        int index = endPosition;
        for (int i = bwtString.Length - 1; i >= 0; i--)
        {
            result[i] = bwtString[index];
            index = firstCountArray[index] + secondCountArray[bwtString[index]];
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

/// <summary>
/// Provides methods for LZW compression and decompression.
/// </summary>
public class LZW
{
    /// <summary>
    /// Compresses the input string using the LZW algorithm.
    /// </summary>
    /// <param name="input">The input string to be compressed.</param>
    /// <returns>A list of integers representing the compressed data.</returns>
    public static List<int> Compress(string input)
    {
        Trie trie = new();
        int currentCode = 256;

        for (int i = 0; i < 256; i++)
        {
            trie.Add(((char)i).ToString(), i);
        }

        List<int> result = [];
        string current = string.Empty;

        foreach (char symbol in input)
        {
            string combined = current + symbol;

            if (trie.Contains(combined))
            {
                current = combined;
            }
            else
            {
                result.Add(trie.GetCodeForEntry(current));

                trie.Add(combined, currentCode++);
                current = symbol.ToString();
            }
        }

        if (!string.IsNullOrEmpty(current))
        {
            result.Add(trie.GetCodeForEntry(current));
        }

        return result;
    }

    /// <summary>
    /// Decompresses the compressed data using the LZW algorithm.
    /// </summary>
    /// <param name="compressedData">The list of integers representing the compressed data.</param>
    /// <returns>The decompressed string.</returns>
    public static string Decompress(List<int> compressedData)
    {
        Dictionary<int, string> dictionary = [];

        for (int i = 0; i < 256; i++)
        {
            dictionary.Add(i, ((char)i).ToString());
        }

        if (compressedData.Count == 0)
        {
            return string.Empty;
        }

        string result = dictionary[compressedData[0]];
        string current = result;

        for (int i = 1; i < compressedData.Count; i++)
        {
            int code = compressedData[i];
            string entry;

            if (dictionary.TryGetValue(code, out string? value))
            {
                entry = value;
            }
            else if (code == dictionary.Count)
            {
                entry = current + current[0];
            }
            else
            {
                throw new InvalidOperationException("Invalid compressed data");
            }

            result += entry;
            dictionary.Add(dictionary.Count, current + entry[0]);
            current = entry;
        }

        return result;
    }
}

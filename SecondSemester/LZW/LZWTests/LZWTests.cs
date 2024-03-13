/// <summary>
/// Test class for the LZW compression and decompression methods.
/// </summary>
[TestClass]
public class LZWTests
{
    /// <summary>
    /// Tests the compression and decompression of a single character, returning the original string.
    /// </summary>
    [TestMethod]
    public void SingleCharacter()
    {
        string input = "A";
        List<int> compressedData = LZW.Compress(input);
        string decompressedResult = LZW.Decompress(compressedData);

        Assert.AreEqual(input, decompressedResult);
    }

    /// <summary>
    /// Tests the compression and decompression of multiple characters, returning the original string.
    /// </summary>
    [TestMethod]
    public void MultipleCharacters()
    {
        string input = "ABCDEF";
        List<int> compressedData = LZW.Compress(input);
        string decompressedResult = LZW.Decompress(compressedData);

        Assert.AreEqual(input, decompressedResult);
    }

    /// <summary>
    /// Tests the compression and decompression of an empty string, returning an empty string.
    /// </summary>
    [TestMethod]
    public void EmptyString()
    {
        string input = "";
        List<int> compressedData = LZW.Compress(input);
        string decompressedResult = LZW.Decompress(compressedData);

        Assert.AreEqual(input, decompressedResult);
    }

    /// <summary>
    /// Tests that compressing a null input throws an <see cref="NullReferenceException"/>.
    /// </summary>
    [TestMethod]
    [ExpectedException(typeof(NullReferenceException))]
    public void CompressNullInput()
    {
        LZW.Compress(null);
    }

    /// <summary>
    /// Tests that decompressing a null input throws an <see cref="NullReferenceException"/>.
    /// </summary>
    [TestMethod]
    [ExpectedException(typeof(NullReferenceException))]
    public void DecompressNullInput()
    {
        LZW.Decompress(null);
    }
}

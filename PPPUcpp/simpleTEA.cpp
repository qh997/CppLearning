#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void encipher(
    const unsigned long *const v,
    unsigned long *const w,
    const unsigned long *const k)
{
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0;
    unsigned long delta = 0x9E3779B9;
    unsigned long n = 32;

    while(n-- > 0)
    {
        y += (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
        sum += delta;
        z += (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
    }

    w[0] = y;
    w[1] = z;
}

int main()
{
    const int nchar = sizeof(long);
    const int kchar = 2 * nchar;

    string op;
    string key("cxylxxjj");
    string infile("my-mail-file.txt");
    string outfile("ETA.txt");

    while (key.size() < kchar)
        key += '0';
    ifstream inf(infile.c_str());
    ofstream outf(outfile.c_str());
    if (!inf || !outf)
        return 1;

    const unsigned long *k =
        reinterpret_cast<const unsigned long *>(key.data());

    unsigned long outptr[2];
    char inbuf[nchar];
    unsigned long * inptr = reinterpret_cast<unsigned long *>(inbuf);
    int count = 0;

    while (inf.get(inbuf[count]))
    {
        outf << hex;
        if (++count == nchar)
        {
            encipher(inptr, outptr, k);
            outf << setw(16) << setfill('0') << outptr[0] << ' '
                 << setw(16) << setfill('0') << outptr[1] << ' ';
            count = 0;
        }
    }

    if (count)
    {
        while (count != nchar)
            inbuf[count++] = '0';
        encipher(inptr, outptr, k);
        outf << outptr[0] << ' ' << outptr[1] << ' ';
    }
}

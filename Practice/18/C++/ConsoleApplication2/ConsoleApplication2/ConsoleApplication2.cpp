#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    setlocale(LC_ALL, "ru");
    int const SizeABC = 26;
    double Probability = 1;
    double ProbabilityDropedOut[SizeABC]{};
    char StopWord[255];
    char words[] = "halloklempnerdasistfantastischfluggegecheimen";
    char ABC[SizeABC]{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    int NumberDropedOutLettet[SizeABC]{};
    cin >> StopWord;
    for (int i = 0; i < strlen(words); i++)
    {
        for (int j = 0; j < SizeABC; j++)
        {
            if (words[i] == ABC[j])
            {
                NumberDropedOutLettet[j] += 1;
            }
        }

    }
    for (int i = 0; i < SizeABC; i++)
    {
        if (NumberDropedOutLettet[i] != 0)
        {
            ProbabilityDropedOut[i] = ((double)NumberDropedOutLettet[i] / strlen(words));
        }
    }

    for (int i = 0; i < strlen(StopWord); i++)
    {
        for (int j = 0; j < SizeABC; j++)
        {
            if (StopWord[i] == ABC[j])
            {
                Probability *= ProbabilityDropedOut[j];
            }
        }
    }
    cout << Probability;

    return 0;
}

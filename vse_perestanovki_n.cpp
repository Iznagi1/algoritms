
void permutations(int n)
{
    vector<int> permutation(0);
    for (int i = 1; i <= n; i++) {
        permutation.push_back(i);
        }
    do {
        // обработать перестановку
    } while (next_permutation(permutation.begin(), permutation.end())); // algorithm библиотека
}

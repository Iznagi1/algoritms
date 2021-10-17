vector<int> subset;
void search(int k) {
    int n = 3;

    if (k == n+1) {
        print(subset);
// обработать подмножество
    } else {
// включить k в подмножество

        subset.push_back(k);
        search(k+1);
        subset.pop_back();
// не включать k в подмножество
        search(k+1);
    }
}

#include <iostream>
#include <vector>

using namespace std;
// �������� �Ҹ��� Ȯ�� �Լ�
bool cantSupply(int& standard, pair<int, int>& next) {
    return (next.first < standard && next.second < standard);
}

int main() {
    // ����ȭ �ڵ�
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ������ �� �Է�
    int n;
    cin >> n;
    // ���� �� �ּ�, �ִ� �䱸�� �Է�
    vector<pair<int, int> > needs;
    for (int i = 0; i < n; i++) {
        int min, max;
        cin >> min >> max;
        needs.push_back({min, max});
    }
    // ��� Ƚ�� �ʱⰪ 1�� �ʱ�ȭ
    int ans = 1;

    // ������ �ּҰ��� ���ذ����� ����
    int standard = needs[0].first;
    // ������ �������� ���� ���� Ȯ��
    for (int i = 0; i < n; ++i) {
        // ������ ���������� �������� ������
        if (cantSupply(standard, needs[i])) {
            ans++;
            standard = needs[i].first;
        }
        // ������ ���������� �����Ѵٸ�
        else {
            standard = max(standard, needs[i].first);
        }
    }
    // ���
    cout << ans;

    return 0;
}

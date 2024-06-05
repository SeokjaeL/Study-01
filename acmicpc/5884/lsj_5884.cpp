#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    // ����ȭ �ڵ�
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ���� ���� �Է�
    int N;
    cin >> N;

    // �� ���� ��ǥ�� �Է�
    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }

    // �ִ� �� �� �ݺ� (�ִ� �� ���� �������� Ŀ�� ����)
    int cnt = 0;
    while (cnt < 3) {
        bool max_xy = false;  // true : x, false : y
        int max_val = 0; // �ִ� �󵵼�
        int max_idx = 0; // �ִ� �󵵸� ���� ��ǥ��
        unordered_map<int, int> dict_x; // x��ǥ�� ��
        unordered_map<int, int> dict_y; // y��ǥ�� ��

        // �� ���� x��ǥ�� y��ǥ�� �󵵸� ���
        for (const auto& cow : cows) {
            // x��ǥ
            dict_x[cow.first]++;
            if (dict_x[cow.first] > max_val) {
                max_val = dict_x[cow.first];
                max_xy = true;
                max_idx = cow.first;
            }
            // y��ǥ
            dict_y[cow.second]++;
            if (dict_y[cow.second] > max_val) {
                max_val = dict_y[cow.second];
                max_xy = false;
                max_idx = cow.second;
            }
        }

        vector<pair<int, int>> new_cows;
        // �ִ� �� ��ǥ�� x��ǥ�� ���
        if (max_xy) {
            // �ش� x��ǥ�� �ҵ��� ����
            for (const auto& cow : cows) {
                if (cow.first != max_idx) {
                    new_cows.push_back(cow);
                }
            }
            cows = new_cows;
        }
        // �ִ� �� ��ǥ�� y��ǥ�� ���
        else {
            // �ش� y��ǥ�� �ҵ��� ����
            for (const auto& cow : cows) {
                if (cow.second != max_idx) {
                    new_cows.push_back(cow);
                }
            }
            cows = new_cows;
        }

        // ��� �Ҹ� �����ߴٸ�
        if (cows.empty()) {
            break;
        }

        cnt++;
    }

    // ��� �Ҹ� ������ �� �ִٸ�
    if (cows.empty()) {
        cout << 1 << endl;
    }
    // ���ٸ�
    else {
        cout << 0 << endl;
    }

    return 0;
}

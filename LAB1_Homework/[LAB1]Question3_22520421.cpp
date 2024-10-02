#include <iostream>
using namespace std;

const int MAX_TOKENS = 100;  // Giới hạn tối đa số lượng token

class AuthenticationManager {
private:
    int timeToLive;  // Thời gian sống của token
    string tokenIds[MAX_TOKENS];  // Lưu tokenId
    int expiryTimes[MAX_TOKENS];  // Lưu thời điểm hết hạn của từng token
    int tokenCount;  // Số lượng token hiện tại

public:
    AuthenticationManager(int ttl) : timeToLive(ttl), tokenCount(0) {}

    // Tạo token với tokenId và thời gian hiện tại
    void generate(string tokenId, int currentTime) {
        if (tokenCount < MAX_TOKENS) {
            tokenIds[tokenCount] = tokenId;
            expiryTimes[tokenCount] = currentTime + timeToLive;
            tokenCount++;
        }
    }

    // Gia hạn token nếu token chưa hết hạn
    void renew(string tokenId, int currentTime) {
        for (int i = 0; i < tokenCount; ++i) {
            if (tokenIds[i] == tokenId && expiryTimes[i] > currentTime) {
                expiryTimes[i] = currentTime + timeToLive;
                return;
            }
        }
    }

    // Đếm số token chưa hết hạn
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (int i = 0; i < tokenCount; ++i) {
            if (expiryTimes[i] > currentTime) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    AuthenticationManager* manager = nullptr;
    int operations;
    cout << "Number of operation"<<" ";
    cin >> operations;

    while (operations--) {
        string operation;
        cin >> operation;

        if (operation == "AuthenticationManager") {
            int ttl;
            cin >> ttl;
            manager = new AuthenticationManager(ttl);
        }
        else if (operation == "generate") {
            string tokenId;
            int currentTime;
            cin >> tokenId >> currentTime;
            manager->generate(tokenId, currentTime);
        }
        else if (operation == "renew") {
            string tokenId;
            int currentTime;
            cin >> tokenId >> currentTime;
            manager->renew(tokenId, currentTime);
        }
        else if (operation == "countUnexpiredTokens") {
            int currentTime;
            cin >> currentTime;
            cout << manager->countUnexpiredTokens(currentTime) << endl;
        }
    }

    return 0;
}

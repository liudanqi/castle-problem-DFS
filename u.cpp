#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
int R, C;
int arr[55][55];
int color[55][55];
int maxRoomArea = 0;int roomNum = 0;
int roomArea;
void DFS(int x, int y) {
	if (color[x][y])
		return;
	++roomArea;
	color[x][y] = roomNum;
	if((arr[x][y] & 1)== 0)DFS(x, y-1);
	if((arr[x][y] & 2)== 0)DFS(x - 1, y);
	if((arr[x][y] & 4)== 0)DFS(x, y + 1);
	if((arr[x][y] & 8)== 0)DFS(x + 1, y);
}
int main() {
	cin >> R >> C;
	for (int i = 1;i <=R;i++) {
		for (int j = 1;j <=C;j++) {
			cin >> arr[i][j];
		}
	}
	memset(color, 0, sizeof(color));
	for (int i = 1;i <=R;++i) {
		for (int j = 1;j <=C;++j) {
			if (!color[i][j]) {
				roomNum++;
				roomArea = 0;
				DFS(i, j);
				maxRoomArea = max(maxRoomArea, roomArea);
			}
		}
	}
	cout << roomNum << endl;
	cout << maxRoomArea << endl;
	return 0;
}
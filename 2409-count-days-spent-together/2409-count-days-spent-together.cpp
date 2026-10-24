class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto converter = [&](string date){
            int month = stoi(date.substr(0, 2));
            int totalDays = stoi(date.substr(3, 2));

            for(int i = 0; i < month - 1; i++){
                totalDays += days[i];
            }
            return totalDays;
        };
        int aliceStart = converter(arriveAlice);
        int aliceEnd = converter(leaveAlice);
        int bobStart = converter(arriveBob);
        int bobEnd = converter(leaveBob);

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        return max(0, end - start + 1);


    }
};
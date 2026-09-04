class Solution {
   public:
    string predictPartyVictory(string senate) {
        int rcount = 0, dcount = 0;
        unordered_set<int> visit;

        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') {
                rcount++;
            } else {
                dcount++;
            }
        }

        do {
            int skipr = 0, skipd = 0;
            for (int i = 0; i < senate.length(); i++) {
                if (visit.find(i) == visit.end()) {
                    if (senate[i] == 'R') {
                        if (dcount > 0) {
                            if (skipr > 0) {
                                skipr--;
                                visit.insert(i);
                                cout<<"R "<<i<<endl;
                            } else {
                                dcount--;
                                skipd++;
                            }
                        } else {
                            return "Radiant";
                        }
                    } else {
                        if (rcount > 0) {
                            if (skipd > 0) {
                                visit.insert(i);
                                cout<<"D "<<i<<endl;
                                skipd--;
                            } else {
                                rcount--;
                                skipr++;
                            }
                        } else {
                            return "Dire";
                        }
                    }
                    cout << rcount << " " << dcount << " " << skipr << " " << skipd << endl;
                }
            }
            int j = 0;
            while(skipr > 0 || skipd > 0 && j < senate.length() && visit.find(j) == visit.end())
            {
                if (senate[j] == 'R') {
                    skipr--;
                    visit.insert(j);
                    cout<<"R "<<j<<endl;
                }
                else
                {
                    skipd--;
                    visit.insert(j);
                    cout<<"D "<<j<<endl;
                }
                j++;
            }
        } while (rcount > 0 && dcount > 0);
        if (rcount > 0) {
            return "Radiant";
        }
        return "Dire";
    }
};
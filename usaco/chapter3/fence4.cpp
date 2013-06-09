/*
ID: silasli2
PROG: fence4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#define EPS 1e-6

using namespace std;
ofstream fout ("fence4.out");
ifstream fin ("fence4.in");

//Computing Geometry Templete Begin
class point
{
    public:
        point(){};
        point(double tx, double ty):x(tx), y(ty) {}
        double x, y;
};

class seg
{
    public:
        seg(){}
        seg(point a, point b) {s = a; t = b;}
        point s, t;
};

double dist(point a, point b)
{
    return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

double multiply(point sp, point ep, point op)
{
    return (((sp.x - op.x) * (ep.y - op.y)) - ((sp.y - op.y) * (ep.x - op.x)));
}

bool checkOnline(seg l, point p)
{
    return ((multiply(l.s, p, l.t) == 0) &&
            (((p.x - l.s.x) * (p.x - l.t.x) <= 0) &&
             ((p.y - l.s.y) * (p.y - l.t.y) <= 0)));
}

point midPoint(point a, point b)
{
    return point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

bool intersect(seg a, seg b)
{
    return ((max(a.s.x, a.t.x) >= min(b.s.x, b.t.x)) &&
            (max(b.s.x, b.t.x) >= min(a.s.x, a.t.x)) &&
            (max(a.s.y, a.t.y) >= min(b.s.y, b.t.y)) &&
            (max(b.s.y, b.t.y) >= min(a.s.y, a.t.y)) &&
            (multiply(b.s, a.t, a.s) * multiply(a.t, b.t, a.s) >= 0) &&
            (multiply(a.s, b.t, b.s) * multiply(b.t, a.t, b.s) >= 0));
}

bool intersect_A(seg a, seg b)
{
    return ((intersect(a, b)) && (!checkOnline(a, b.s)) &&
            (!checkOnline(a, b.t)) && (!checkOnline(b, a.s)) &&
            (!checkOnline(b, a.t)));
}

//Computing Geometry Templete End
int N, vis_count;
point p[205], viewer;
seg s[205];
bool vis[205];



int init(){
    fin>>N;
    fin>>viewer.x>>viewer.y;
    for (int i=0;i<N;i++)
        fin>>p[i].x>>p[i].y;
    p[N] = p[0];
    for (int i=0;i<N-1;i++)
        s[i] = seg(p[i], p[i+1]);
    s[N-1] = seg(p[0], p[N-1]);
    return 0;
}

int check(int x, seg a){
    if (dist(a.s, a.t) < EPS) return 0;

    int flag=0;
    for (int i=0;i<N;i++){
        if (i!=x){//check other segments
            if (intersect(seg(viewer, a.s), s[i]) && intersect(seg(viewer, a.t), s[i])){
                flag = 1;
                break;
            }
            if (intersect_A(seg(viewer, a.s), s[i]) || intersect_A(seg(viewer, a.t), s[i])){
                flag = 2;
            }
        }
    }
    if (flag ==0) return 1;
    else if (flag ==1) return 0;
    else return ((check(x, seg(a.s, midPoint(a.s, a.t))))||(check(x, seg(midPoint(a.s, a.t), a.t))));

    return 0;
}

int solve(){
    memset(vis, 0, sizeof(vis));
    vis_count=0;
    for (int i=0;i<N;i++){
        if (check(i, s[i])){
            vis_count++;
            vis[i] = 1;
        }
    }
    return 0;
}
int output(){
    if (vis_count==0){
        fout<<"NOFENCE"<<endl;
        cout<<"NOFENCE"<<endl;
        return 0;
    }
    fout<<vis_count<<endl;
    cout<<vis_count<<endl;
    for (int i=0;i<N-2;i++)
        if (vis[i]){
            fout<<s[i].s.x<<' '<<s[i].s.y<<' '<<s[i].t.x<<' '<<s[i].t.y<<endl;
            cout<<s[i].s.x<<' '<<s[i].s.y<<' '<<s[i].t.x<<' '<<s[i].t.y<<endl;
        }
    int i = N-1;
    if (vis[i]){
            fout<<s[i].s.x<<' '<<s[i].s.y<<' '<<s[i].t.x<<' '<<s[i].t.y<<endl;
            cout<<s[i].s.x<<' '<<s[i].s.y<<' '<<s[i].t.x<<' '<<s[i].t.y<<endl;
    }
    i = N-2;
    if (vis[i]){
            fout<<s[i].s.x<<' '<<s[i].s.y<<' '<<s[i].t.x<<' '<<s[i].t.y<<endl;
            cout<<s[i].s.x<<' '<<s[i].s.y<<' '<<s[i].t.x<<' '<<s[i].t.y<<endl;
    }
    return 0;
}

int main() {
    init();
    solve();
    output();
    return 0;
}

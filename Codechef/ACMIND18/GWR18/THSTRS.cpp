#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000003
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[500010];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

bool compa(string &a, string &c, int x,int y)
{
  if(a.size()-x!=y+1) return false;
  bool boo = false;
  int count =0;
  for(int i=x;i<y;i++)
  {
    if(a[i]!=c[count]) return false;
    count++;
  }
  return true;
}

bool compb(string &a, string &c, int x,int y)
{
  if(x+1!=c.size()-y) return false;
  bool boo = false;
  int count =y;
  for(int i=0;i<x;i++)
  {
    if(a[i]!=c[count]) return false;
    count++;
  }
  return true;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    string a,b,c;
    scr(a);scr(b);scr(c);

    vector<vector<int> > hashta(1000010);
    vector<vector<int> > hashtb(1000010);

    string k1,k2;
    ll hasha = 0, hashb = 0,hashc = 0;
    int na = a.size(),nb = b.size(), nc = c.size();
    for(int i=0;i<min(c.size(),a.size());i++)
    {
      // na-i-1;
      ll a1 = power(26,i,MOD);
      a1*=a[na-i-1];a1%=MOD;
      hasha+=a1;
      hasha%=MOD;
      // t(i,hasha);
      hashta[hasha].pu(na-i-1);
    }

    set<int> a1,b1;

    for(int i=0;i<c.size();i++)
    {
      hashc*=26;
      hashc+=c[i];
      hashc%=MOD;
      // t(i,hashc);
      if(!hashta[hashc].empty())
      {
        for(int j=0;j<hashta.size();j++)
        {
          // if(compa(a,c,hashta[hashc][j], i)) {a1.insert(i);break;}
          a1.insert(i);break;
        }
      }
    }

    for(int i=0;i<min(c.size(),b.size());i++)
    {
      // na-i-1;
      hashb*=26;
      hashb+=b[i];
      hashb%=MOD;   
      // t(i,hashb);  
      hashtb[hashb].pu(i);
    }

    hashc = 0;
    for(int i=0;i<c.size();i++)
    {
      // hashc*=26;
      // hashc+=c[c.size()-i-1]-'a';
      ll a1 = power(26,i,MOD);
      a1*=c[nc-i-1];a1%=MOD;
      hashc+=a1;
      hashc%=MOD;
      // t(i,hashc);
      if(!hashtb[hashc].empty())
      {
        for(int j=0;j<hashtb.size();j++)
        {
          // if(compb(b,c,hashtb[hashc][j],c.size()-i-1)) {b1.insert(c.size()-i-1);break;
          b1.insert(c.size()-i-1);break;
        }
      }
    }
    
    b1.insert(c.size());
    set<int> :: iterator it;
    int min1 = INF;
    a1.insert(-1);
    for(it=a1.begin();it!=a1.end();it++)
    {

      int a = *b1.upper_bound(*it);
      min1 = min(a-*it-1,min1);
      // t(*it, a,min1);
    }

    // for(it=b1.begin();it!=b1.end();it++)
    // {
    //   int a = *a1.upper_bound(*it);
    //   min1 = min(abs(a-*it)-1,min1);
    // }

    if(min1==INF) cout<<a.size()+b.size()+c.size()<<endl;
    else cout<<min1+a.size()+b.size()<<endl;
  }
  return 0;
}

/*
1
abc
cde
bccd


i : 191858 hashc : 519575
i : 191859 hashc : 509008
i : 191860 hashc : 234266
i : 191861 hashc : 90995
i : 191862 hashc : 365961
i : 191863 hashc : 515056
i : 191864 hashc : 391514
i : 191865 hashc : 179431
i : 191866 hashc : 665291
i : 191867 hashc : 297612
i : 191868 hashc : 737988
i : 191869 hashc : 187728
i : 191870 hashc : 881013
i : 191871 hashc : 906369
i : 191872 hashc : 565622
i : 191873 hashc : 706227
i : 191874 hashc : 361945
i : 191875 hashc : 410640
i : 191876 hashc : 676707
i : 191877 hashc : 594428
i : 191878 hashc : 455180
i : 191879 hashc : 834744
i : 191880 hashc : 703378
i : 191881 hashc : 287871
i : 191882 hashc : 484722
i : 191883 hashc : 602833
i : 191884 hashc : 673710
i : 191885 hashc : 516506
i : 191886 hashc : 429214
i : 191887 hashc : 159628
i : 191888 hashc : 150413
i : 191889 hashc : 910826
i : 191890 hashc : 681504
i : 191891 hashc : 719150
i : 191892 hashc : 697943
i : 191893 hashc : 146561
i : 191894 hashc : 810674
i : 191895 hashc : 77558
i : 191896 hashc : 16599
i : 191897 hashc : 431671
i : 191898 hashc : 223510
i : 191899 hashc : 811342
i : 191900 hashc : 94926
i : 191901 hashc : 468167
i : 191902 hashc : 172403
i : 191903 hashc : 482563
i : 191904 hashc : 546699
i : 191905 hashc : 214229
i : 191906 hashc : 570036
i : 191907 hashc : 820991
i : 191908 hashc : 345800
i : 191909 hashc : 990873
i : 191910 hashc : 762720
i : 191911 hashc : 830760
i : 191912 hashc : 599794
i : 191913 hashc : 594696
i : 191914 hashc : 462148
i : 191915 hashc : 15909
i : 191916 hashc : 413731
i : 191917 hashc : 757073
i : 191918 hashc : 683938
i : 191919 hashc : 782434
i : 191920 hashc : 343321
i : 191921 hashc : 926419
i : 191922 hashc : 86919
i : 191923 hashc : 259985
i : 191924 hashc : 759689
i : 191925 hashc : 751954
i : 191926 hashc : 550844
i : 191927 hashc : 321999
i : 191928 hashc : 372047
i : 191929 hashc : 673292
i : 191930 hashc : 505638
i : 191931 hashc : 146646
i : 191932 hashc : 812884
i : 191933 hashc : 135018
i : 191934 hashc : 510556
i : 191935 hashc : 274514
i : 191936 hashc : 137440
i : 191937 hashc : 573528
i : 191938 hashc : 911783
i : 191939 hashc : 706386
i : 191940 hashc : 366079
i : 191941 hashc : 518124
i : 191942 hashc : 471282
i : 191943 hashc : 253393
i : 191944 hashc : 588297
i : 191945 hashc : 295774
i : 191946 hashc : 690200
i : 191947 hashc : 945246
i : 191948 hashc : 576421
i : 191949 hashc : 987001
i : 191950 hashc : 662048
i : 191951 hashc : 213294
i : 191952 hashc : 545726
i : 191953 hashc : 188931
i : 191954 hashc : 912291
i : 191955 hashc : 719594
i : 191956 hashc : 709487
i : 191957 hashc : 446705
i : 191958 hashc : 614394
i : 191959 hashc : 974296
i : 191960 hashc : 331718
i : 191961 hashc : 624741
i : 191962 hashc : 243315
i : 191963 hashc : 326269
i : 191964 hashc : 483067
i : 191965 hashc : 559803
i : 191966 hashc : 554933
i : 191967 hashc : 428313
i : 191968 hashc : 136202
i : 191969 hashc : 541340
i : 191970 hashc : 74895
i : 191971 hashc : 947364
i : 191972 hashc : 631489
i : 191973 hashc : 418763
i : 191974 hashc : 887905
i : 191975 hashc : 85558
i : 191976 hashc : 224599
i : 191977 hashc : 839656
i : 191978 hashc : 831090
i : 191979 hashc : 608374
i : 191980 hashc : 817776
i : 191981 hashc : 262210
i : 191982 hashc : 817539
i : 191983 hashc : 256048
i : 191984 hashc : 657327
i : 191985 hashc : 90548
i : 191986 hashc : 354339
i : 191987 hashc : 212884
i : 191988 hashc : 535066
i : 191989 hashc : 911774
i : 191990 hashc : 706152
i : 191991 hashc : 359995
i : 191992 hashc : 359940
i : 191993 hashc : 358510
i : 191994 hashc : 321330
i : 191995 hashc : 354653
i : 191996 hashc : 221048
i : 191997 hashc : 747330
i : 191998 hashc : 430620
i : 191999 hashc : 196184
i : 192000 hashc : 100866
i : 192001 hashc : 622607
i : 192002 hashc : 187831
i : 192003 hashc : 883691
i : 192004 hashc : 975997
i : 192005 hashc : 375944
i : 192006 hashc : 774614
i : 192007 hashc : 140001
i : 192008 hashc : 640114
i : 192009 hashc : 643013
i : 192010 hashc : 718387
i : 192011 hashc : 678105
i : 192012 hashc : 630776
i : 192013 hashc : 400225
i : 192014 hashc : 405917
i : 192015 hashc : 553909
i : 192016 hashc : 401689
i : 192017 hashc : 443981
i : 192018 hashc : 543570
i : 192019 hashc : 132875
i : 192020 hashc : 454838
i : 192021 hashc : 825852
i : 192022 hashc : 472186
i : 192023 hashc : 276897
i : 192024 hashc : 199398
i : 192025 hashc : 184430
i : 192026 hashc : 795265
i : 192027 hashc : 676927
i : 192028 hashc : 600148
i : 192029 hashc : 603900
i : 192030 hashc : 701452
i : 192031 hashc : 237795
i : 192032 hashc : 182749
i : 192033 hashc : 751559
i : 192034 hashc : 540574
i : 192035 hashc : 54979
i : 192036 hashc : 429548
i : 192037 hashc : 168312
i : 192038 hashc : 376197
i : 192039 hashc : 781192
i : 192040 hashc : 311029
i : 192041 hashc : 86827
i : 192042 hashc : 257593
i : 192043 hashc : 697497
i : 192044 hashc : 134965
i : 192045 hashc : 509178
i : 192046 hashc : 238686
i : 192047 hashc : 205915
i : 192048 hashc : 353872
i : 192049 hashc : 200742
i : 192050 hashc : 219374
i : 192051 hashc : 703806
i : 192052 hashc : 298999
i : 192053 hashc : 774050
i : 192054 hashc : 125337
i : 192055 hashc : 258850
i : 192056 hashc : 730179
i : 192057 hashc : 984697
i : 192058 hashc : 602144
i : 192059 hashc : 655796
i : 192060 hashc : 50742
i : 192061 hashc : 319386
i : 192062 hashc : 304109
i : 192063 hashc : 906910
i : 192064 hashc : 579688
i : 192065 hashc : 71940
i : 192066 hashc : 870534
i : 192067 hashc : 633915
i : 192068 hashc : 481839
i : 192069 hashc : 527875
i : 192070 hashc : 724808
i : 192071 hashc : 845051
i : 192072 hashc : 971360
i : 192073 hashc : 255382
i : 192074 hashc : 640011
i : 192075 hashc : 640335
i : 192076 hashc : 648759
i : 192077 hashc : 867783
i : 192078 hashc : 562389
i : 192079 hashc : 622169
i : 192080 hashc : 176443
i : 192081 hashc : 587603
i : 192082 hashc : 277730
i : 192083 hashc : 221056
i : 192084 hashc : 747538
i : 192085 hashc : 436028
i : 192086 hashc : 336792
i : 192087 hashc : 756665
i : 192088 hashc : 673330
i : 192089 hashc : 506626
i : 192090 hashc : 172334
i : 192091 hashc : 480769
i : 192092 hashc : 500055
i : 192093 hashc : 1488
i : 192094 hashc : 38785
i : 192095 hashc : 8504
i : 192096 hashc : 221201
i : 192097 hashc : 751308
i : 192098 hashc : 534048
i : 192099 hashc : 885306
i : 192100 hashc : 17984
i : 192101 hashc : 467681
i : 192102 hashc : 159767
i : 192103 hashc : 154027
i : 192104 hashc : 4787
i : 192105 hashc : 124559
i : 192106 hashc : 238622
i : 192107 hashc : 204251
i : 192108 hashc : 310608
i : 192109 hashc : 75881
i : 192110 hashc : 973000
i : 192111 hashc : 298022
i : 192112 hashc : 748648
i : 192113 hashc : 464888
i : 192114 hashc : 87149
i : 192115 hashc : 265965
i : 192116 hashc : 915169
i : 192117 hashc : 794422
i : 192118 hashc : 655009
i : 192119 hashc : 30280
i : 192120 hashc : 787377
i : 192121 hashc : 471839
i : 192122 hashc : 267875
i : 192123 hashc : 964829
i : 192124 hashc : 85576
i : 192125 hashc : 225067
i : 192126 hashc : 851824
i : 192127 hashc : 147455
i : 192128 hashc : 833918
i : 192129 hashc : 681902
i : 192130 hashc : 729498
i : 192131 hashc : 966991
i : 192132 hashc : 141788
i : 192133 hashc : 686576
i : 192134 hashc : 851022
i : 192135 hashc : 126603
i : 192136 hashc : 291766
i : 192137 hashc : 585992
i : 192138 hashc : 235844
i : 192139 hashc : 132023
i : 192140 hashc : 432686
i : 192141 hashc : 249900
i : 192142 hashc : 497479
i : 192143 hashc : 934515
i : 192144 hashc : 297415
i : 192145 hashc : 732866
i : 192146 hashc : 54556
i : 192147 hashc : 418550
i : 192148 hashc : 882367
i : 192149 hashc : 941573
i : 192150 hashc : 480923
i : 192151 hashc : 504059
i : 192152 hashc : 105592
i : 192153 hashc : 745483
i : 192154 hashc : 382598
i : 192155 hashc : 947618
i : 192156 hashc : 638093
i : 192157 hashc : 590467
i : 192158 hashc : 352194
i : 192159 hashc : 157114
i : 192160 hashc : 85049
i : 192161 hashc : 211365
i : 192162 hashc : 495572
i : 192163 hashc : 884933
i : 192164 hashc : 8286
i : 192165 hashc : 215533
i : 192166 hashc : 603940
i : 192167 hashc : 702492
i : 192168 hashc : 264835
i : 192169 hashc : 885789
i : 192170 hashc : 30542
i : 192171 hashc : 794189
i : 192172 hashc : 648951
i : 192173 hashc : 872775
i : 192174 hashc : 692181
i : 192175 hashc : 996752
i : 192176 hashc : 915574
i : 192177 hashc : 804952
i : 192178 hashc : 928789
i : 192179 hashc : 148539
i : 192180 hashc : 862102
i : 192181 hashc : 414683
i : 192182 hashc : 781825
i : 192183 hashc : 327487
i : 192184 hashc : 514735
i : 192185 hashc : 383168
i : 192186 hashc : 962438
i : 192187 hashc : 23410
i : 192188 hashc : 608757
i : 192189 hashc : 827734
i : 192190 hashc : 521118
i : 192191 hashc : 549126
i : 192192 hashc : 277331
i : 192193 hashc : 210682
i : 192194 hashc : 477814
i : 192195 hashc : 423225
i : 192196 hashc : 3914
i : 192197 hashc : 101861
i : 192198 hashc : 648477
i : 192199 hashc : 860451
i : 192200 hashc : 371757
i : 192201 hashc : 665752
i : 192202 hashc : 309598
i : 192203 hashc : 49621
i : 192204 hashc : 290240
i : 192205 hashc : 546316
i : 192206 hashc : 204271
i : 192207 hashc : 311128
i : 192208 hashc : 89401
i : 192209 hashc : 324517
i : 192210 hashc : 437515
i : 192211 hashc : 375454
i : 192212 hashc : 761874
i : 192213 hashc : 808764
i : 192214 hashc : 27898
i : 192215 hashc : 725445
i : 192216 hashc : 861613
i : 192217 hashc : 401969
i : 192218 hashc : 451261
i : 192219 hashc : 732850
i : 192220 hashc : 54140
i : 192221 hashc : 407734
i : 192222 hashc : 601151
i : 192223 hashc : 629978
i : 192224 hashc : 379477
i : 192225 hashc : 866472
i : 192226 hashc : 528303
i : 192227 hashc : 735936
i : 192228 hashc : 134376
i : 192229 hashc : 493864
i : 192230 hashc : 840525
i : 192231 hashc : 853684
i : 192232 hashc : 195815
i : 192233 hashc : 91272
i : 192234 hashc : 373163
i : 192235 hashc : 702308
i : 192236 hashc : 260051
i : 192237 hashc : 761405
i : 192238 hashc : 796570
i : 192239 hashc : 710857
i : 192240 hashc : 482325
i : 192241 hashc : 540511
i : 192242 hashc : 53341
i : 192243 hashc : 386960
i : 192244 hashc : 61027
i : 192245 hashc : 586796
i : 192246 hashc : 256748
i : 192247 hashc : 675527
i : 192248 hashc : 563748
i : 192249 hashc : 657503
i : 192250 hashc : 95124
i : 192251 hashc : 473315
i : 192252 hashc : 306251
i : 192253 hashc : 962602
i : 192254 hashc : 27674
i : 192255 hashc : 719621
i : 192256 hashc : 710189
i : 192257 hashc : 464957
i : 192258 hashc : 88943
i : 192259 hashc : 312609
i : 192260 hashc : 127907
i : 192261 hashc : 325670
i : 192262 hashc : 467493
i : 192263 hashc : 154879
i : 192264 hashc : 26939
i : 192265 hashc : 700511
i : 192266 hashc : 213329
i : 192267 hashc : 546636
i : 192268 hashc : 212591
i : 192269 hashc : 527448
i : 192270 hashc : 713706
i : 192271 hashc : 556399
i : 192272 hashc : 466429
i : 192273 hashc : 127215
i : 192274 hashc : 307678
i : 192275 hashc : 999704
i : 192276 hashc : 992326
i : 192277 hashc : 800498
i : 192278 hashc : 812985
i : 192279 hashc : 137644
i : 192280 hashc : 578832
i : 192281 hashc : 49684
i : 192282 hashc : 291878
i : 192283 hashc : 588904
i : 192284 hashc : 311556
i : 192285 hashc : 100529
i : 192286 hashc : 613845
i : 192287 hashc : 960022
i : 192288 hashc : 960597
i : 192289 hashc : 975547
i : 192290 hashc : 364244
i : 192291 hashc : 470414
i : 192292 hashc : 230825
i : 192293 hashc : 1529
i : 192294 hashc : 39851
i : 192295 hashc : 36220
i : 192296 hashc : 941817
i : 192297 hashc : 487267
i : 192298 hashc : 669003
i : 192299 hashc : 394124
i : 192300 hashc : 247291
i : 192301 hashc : 429645
i : 192302 hashc : 170834
i : 192303 hashc : 441769
i : 192304 hashc : 486058
i : 192305 hashc : 637569
i : 192306 hashc : 576843
i : 192307 hashc : 997973
i : 192308 hashc : 947320
i : 192309 hashc : 630345
i : 192310 hashc : 389019
i : 192311 hashc : 114561
i : 192312 hashc : 978677
i : 192313 hashc : 445624
i : 192314 hashc : 586288
i : 192315 hashc : 243540
i : 192316 hashc : 332119
i : 192317 hashc : 635167
i : 192318 hashc : 514391
i : 192319 hashc : 374224
i : 192320 hashc : 729894
i : 192321 hashc : 977287
i : 192322 hashc : 409484
i : 192323 hashc : 646651
i : 192324 hashc : 812975
i : 192325 hashc : 137384
i : 192326 hashc : 572072
i : 192327 hashc : 873927
i : 192328 hashc : 722133
i : 192329 hashc : 775501
i : 192330 hashc : 163063
i : 192331 hashc : 239723
i : 192332 hashc : 232877
i : 192333 hashc : 54881
i : 192334 hashc : 427000
i : 192335 hashc : 102064
i : 192336 hashc : 653755
i : 192337 hashc : 997679
i : 192338 hashc : 939676
i : 192339 hashc : 431601
i : 192340 hashc : 221690
i : 192341 hashc : 764022
i : 192342 hashc : 864612
i : 192343 hashc : 479943
i : 192344 hashc : 478579
i : 192345 hashc : 443115
i : 192346 hashc : 521054
i : 192347 hashc : 547462
i : 192348 hashc : 234067
i : 192349 hashc : 85821
i : 192350 hashc : 231437
i : 192351 hashc : 17441
i : 192352 hashc : 453563
i : 192353 hashc : 792702
i : 192354 hashc : 610289
i : 192355 hashc : 867566
i : 192356 hashc : 556747
i : 192357 hashc : 475477
i : 192358 hashc : 362463
i : 192359 hashc : 424108
i : 192360 hashc : 26872
i : 192361 hashc : 698769
i : 192362 hashc : 168037
i : 192363 hashc : 369047
i : 192364 hashc : 595292
i : 192365 hashc : 477644
i : 192366 hashc : 418805
i : 192367 hashc : 888997
i : 192368 hashc : 113950
i : 192369 hashc : 962791
i : 192370 hashc : 32588
i : 192371 hashc : 847385
i : 192372 hashc : 32041
i : 192373 hashc : 833163
i : 192374 hashc : 662272
i : 192375 hashc : 219118
i : 192376 hashc : 697150
i : 192377 hashc : 125943
i : 192378 hashc : 274606
i : 192379 hashc : 139832
i : 192380 hashc : 635720
i : 192381 hashc : 528769
i : 192382 hashc : 748052
i : 192383 hashc : 449392
i : 192384 hashc : 684256
i : 192385 hashc : 790702
i : 192386 hashc : 558289
i : 192387 hashc : 515569
i : 192388 hashc : 404852
i : 192389 hashc : 526219
i : 192390 hashc : 681752
i : 192391 hashc : 725598
i : 192392 hashc : 865591
i : 192393 hashc : 505397
i : 192394 hashc : 140380
i : 192395 hashc : 649968
i : 192396 hashc : 899217
i : 192397 hashc : 379670
i : 192398 hashc : 871490
i : 192399 hashc : 658771
i : 192400 hashc : 128092
i : 192401 hashc : 330480
i : 192402 hashc : 592553
i : 192403 hashc : 406430
i : 192404 hashc : 567247
i : 192405 hashc : 748477
i : 192406 hashc : 460442
i : 192407 hashc : 971556
i : 192408 hashc : 260478
i : 192409 hashc : 772507
i : 192410 hashc : 85219
i : 192411 hashc : 215785
i : 192412 hashc : 610492
i : 192413 hashc : 872844
i : 192414 hashc : 693975
i : 192415 hashc : 43393
i : 192416 hashc : 128312
i : 192417 hashc : 336200
i : 192418 hashc : 741273
i : 192419 hashc : 273138
i : 192420 hashc : 101664
i : 192421 hashc : 643355
i : 192422 hashc : 727279
i : 192423 hashc : 909297
i : 192424 hashc : 641750
i : 192425 hashc : 685549
i : 192426 hashc : 824320
i : 192427 hashc : 432354
i : 192428 hashc : 241268
i : 192429 hashc : 273047
i : 192430 hashc : 99298
i : 192431 hashc : 581839
i : 192432 hashc : 127866
i : 192433 hashc : 324604
i : 192434 hashc : 439777
i : 192435 hashc : 434266
i : 192436 hashc : 290980
i : 192437 hashc : 565556
i : 192438 hashc : 704511
i : 192439 hashc : 317329
i : 192440 hashc : 250627
i : 192441 hashc : 516381
i : 192442 hashc : 425964
i : 192443 hashc : 75128
i : 192444 hashc : 953422
i : 192445 hashc : 788997
i : 192446 hashc : 513959
i : 192447 hashc : 362992
i : 192448 hashc : 437862
i : 192449 hashc : 384476
i : 192450 hashc : 996446
i : 192451 hashc : 907618
i : 192452 hashc : 598096
i : 192453 hashc : 550548
i : 192454 hashc : 314303
i : 192455 hashc : 171951
i : 192456 hashc : 470811
i : 192457 hashc : 241147
i : 192458 hashc : 269901
i : 192459 hashc : 17502
i : 192460 hashc : 455149
i : 192461 hashc : 833938
i : 192462 hashc : 682422
i : 192463 hashc : 743018
i : 192464 hashc : 318508
i : 192465 hashc : 281281
i : 192466 hashc : 313382
i : 192467 hashc : 148005
i : 192468 hashc : 848218
i : 192469 hashc : 53699
i : 192470 hashc : 396268
i : 192471 hashc : 303035
i : 192472 hashc : 878986
i : 192473 hashc : 853667
i : 192474 hashc : 195373
i : 192475 hashc : 79780
i : 192476 hashc : 74371
i : 192477 hashc : 933740
i : 192478 hashc : 277265
i : 192479 hashc : 208966
i : 192480 hashc : 433198
i : 192481 hashc : 263212
i : 192482 hashc : 843591
i : 192483 hashc : 933400
i : 192484 hashc : 268425
i : 192485 hashc : 979129
i : 192486 hashc : 457376
i : 192487 hashc : 891840
i : 192488 hashc : 187868
i : 192489 hashc : 884653
i : 192490 hashc : 1006
i : 192491 hashc : 26253
i : 192492 hashc : 682675
i : 192493 hashc : 749596
i : 192494 hashc : 489536
i : 192495 hashc : 727997
i : 192496 hashc : 927965
i : 192497 hashc : 127115
i : 192498 hashc : 305078
i : 192499 hashc : 932104
i : 192500 hashc : 234729
i : 192501 hashc : 103033
i : 192502 hashc : 678949
i : 192503 hashc : 652720
i : 192504 hashc : 970769
i : 192505 hashc : 240016
i : 192506 hashc : 240495
i : 192507 hashc : 252949
i : 192508 hashc : 576753
i : 192509 hashc : 995633
i : 192510 hashc : 886480
i : 192511 hashc : 48508
i : 192512 hashc : 261302
i : 192513 hashc : 793931
i : 192514 hashc : 642243
i : 192515 hashc : 698367
i : 192516 hashc : 157585
i : 192517 hashc : 97295
i : 192518 hashc : 529761
i : 192519 hashc : 773844
i : 192520 hashc : 119981
i : 192521 hashc : 119594
i : 192522 hashc : 109532
i : 192523 hashc : 847923
i : 192524 hashc : 46029
i : 192525 hashc : 196848
i : 192526 hashc : 118130
i : 192527 hashc : 71468
i : 192528 hashc : 858262
i : 192529 hashc : 314843
i : 192530 hashc : 185991
i : 192531 hashc : 835851
i : 192532 hashc : 732160
i : 192533 hashc : 36200
i : 192534 hashc : 941297
i : 192535 hashc : 473747
i : 192536 hashc : 317483
i : 192537 hashc : 254631
i : 192538 hashc : 620485
i : 192539 hashc : 132659
i : 192540 hashc : 449222
i : 192541 hashc : 679836
i : 192542 hashc : 675782
i : 192543 hashc : 570378
i : 192544 hashc : 829883
i : 192545 hashc : 576992
i : 192546 hashc : 1844
i : 192547 hashc : 48041
i : 192548 hashc : 249160
i : 192549 hashc : 478239
i : 192550 hashc : 434275
i : 192551 hashc : 291214
i : 192552 hashc : 571640
i : 192553 hashc : 862695
i : 192554 hashc : 430101
i : 192555 hashc : 182690
i : 192556 hashc : 750025
i : 192557 hashc : 500690
i : 192558 hashc : 17998
i : 192559 hashc : 468045
i : 192560 hashc : 169231
i : 192561 hashc : 400091
i : 192562 hashc : 402433
i : 192563 hashc : 463325
i : 192564 hashc : 46511
i : 192565 hashc : 209380
i : 192566 hashc : 443962
i : 192567 hashc : 543076
i : 192568 hashc : 120031
i : 192569 hashc : 120894
i : 192570 hashc : 143332
i : 192571 hashc : 726720
*/
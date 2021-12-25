class File {
   int fd;
};
You7:44 PM
```
class File {
 File(File&& otherFile) {
  fd = other.fd;
  other.fd = -1;  
}
};```
Wolfgang Wander7:45 PM
double * p = new double [5];
Wolfgang Wander7:48 PM
delete p;
double *p = malloc( 5 * sizeof(double));
free(p);
Wolfgang Wander7:51 PM
/dev/random
You7:53 PM
1 - sign 8 mantissa 23 rest.
You8:04 PM

float genRandomDouble(ifstream& inData) {
    char a, b, c;
    inData >> a >> b >> c;
    char* p = new char[4];
    p[1] = a, p[2] = b, p[3] = c;
    // Under the assumption that mantissa is 7 bits and sign is one bit
    float result  = *((float*) p);
   delete []p;
   return result;
}

int main() {
    __;
    ifstream inData;
    inData.open("/dev/random");
    if (!inData) {
        // Error in opening file
        return 0;
    }

    cout << genRandomDouble(inData) << "\n";
    return 0
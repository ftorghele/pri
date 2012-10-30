class Number {
    public:
        Number() : number(0){}
        Number(float _n) : number(_n) {}

        bool operator< (const Number &o) {
            return number < o.number;
        }

        float number;

    friend std::ostream& operator<<(std::ostream& output, const Number &o) {
        output << o.number;
        return output;
    }
};

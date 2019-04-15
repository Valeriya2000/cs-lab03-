#include <iostream>
#include <vector>

using namespace std;
vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}
void
find_minmax(vector<double> numbers, double& min, double& max)
{
    min = numbers[0];
    max = numbers[0];
    for(double number : numbers)
    {
        if(number<min)
            min=number;
        if(number>max)
            max=number;
    }
}
vector<size_t>
make_histogram(const vector<double>& numbers, size_t bin_count)
{
    double min ;
    double max ;
    find_minmax(numbers, min, max);

        vector<size_t> bins(bin_count);
        for (double number : numbers)
        {
            size_t bin = (size_t)((number - min) / (max - min) * bin_count);
            if (bin == bin_count)
            {
                bin--;
            }
            bins[bin]++;
        }
    return bins;
}
void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg width='" << width << "' height='" << height << "' "
         << "viewBox='0 0 " << width << " " << height << "' "
         << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}
void svg_text(double left, double baseline, string text)
{
    cout<<"<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";
}
void svg_rect(double x, double y, double width, double height)
{
    cout<< "<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' />";
}
void
show_histogram_svg(const vector<size_t>& bins) {
    svg_begin(400, 300);
    svg_text(20, 20, to_string(bins[0]));
    svg_rect(50, 0, bins[0] * 10, 30);
    svg_end();
}
int
main() {
    // ¬вод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    const auto bins = make_histogram(numbers, bin_count);

    show_histogram_svg(bins);
    return 0;
}

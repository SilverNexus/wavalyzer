#pragma once
#include "gui.hpp"
#include <vector>
#include <string>

namespace wavalyzer::gui {
    class histogram : public diagram {
    private:
        std::vector<float> values;
        float min_hertz, max_hertz, step_hertz;
        size_t buckets;

        float left_hertz, right_hertz;
        std::vector<sf::RectangleShape> bars;
        std::vector<float> bar_values;

        std::string hertz_to_string(int hertz);

        void update_bars();
        int hertz_to_index(float hertz);

        float get_bucket_width();
        float get_bucket_width_normalized();
        float get_bucket_start_alpha(int bucket);
        float get_bucket_start_frequency(int bucket);

    public:
        histogram(const std::vector<float>& _values,
                  float _min_hertz,
                  float _max_hertz,
                  float _step_hertz,
                  size_t _buckets);

        std::map<float, std::string> get_y_labels();
        std::pair<float, float> get_full_x_range();
        float get_x_granularity();
        std::map<float, std::string> get_x_labels();
        void set_x_range(std::pair<float, float> new_range);
        void draw(sf::RenderTarget* target, std::pair<int, int> bottom_left, std::pair<int, int> size);
 
    };
}
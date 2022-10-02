#include <vector>

namespace powerRanges {
    template <class T>
    class rangeBounds {
    private:
        T from;
        T to;
    public:
        rangeBounds(T from, T to) {
            this->from = from;
            this->to = to;
        }

        T getFrom() { return this->from; }
        T getTo() { return this->to; }
    };

    template <class T>
    std::vector<T>* range(T begin, T end) {
        auto rangeSet = new std::vector<T>();
        for (T i = begin; i != end; i++) {
            rangeSet->push_back(i);
        }
        rangeSet->push_back(end);
        return rangeSet;
    }

    template <class T>
    std::vector<T>* range(rangeBounds<T> pair) {
        return range<T>(pair.geFrom(), pair.getTo());
    }

    template <class T>
    std::vector<T>* range(rangeBounds<T> *pair) {
        return range<T>(pair->getFrom(), pair->getTo());
    }

    template <class T>
    std::vector<T>* unifiedRange(std::vector<rangeBounds<T>*> *pairs) {
        auto rangeSet = new std::vector<T>();
        for (auto it = pairs->begin(); it != pairs->end(); ++it) {
            auto rangeSubset = range(*it);
            rangeSet->insert(rangeSet->end(), rangeSubset->begin(), rangeSubset->end());
        }
        return rangeSet;
    }
}
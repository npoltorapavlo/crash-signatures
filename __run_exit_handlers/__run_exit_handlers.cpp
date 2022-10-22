#include <memory>
#include <vector>

struct Buffer {
    std::vector<int> buff;

    static std::shared_ptr<Buffer> instance();

    void add(int i)
    {
        buff.emplace_back(i);
    }
};

struct Input {
    Input() { Buffer::instance()->add(0); }
    ~Input() { Buffer::instance()->add(1); }
};

static Input input;

std::shared_ptr<Buffer> buffer;

std::shared_ptr<Buffer> Buffer::instance()
{
    if (!buffer)
        buffer.reset(new Buffer());
    return buffer;
}

int main()
{
    return 0;
}

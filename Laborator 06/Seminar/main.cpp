#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


struct JsonValue {
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out) = 0;
};

struct NumberValue : JsonValue {
    long long value;

    NumberValue(long long x) : value(x) {
    }

    void print(std::ostream& out) override {
        out << value;
    }
};

struct StringValue : JsonValue {
    char value[256];

    StringValue(const char* x) {
        strcpy(value, x);
    }

    void print(std::ostream& out) override {
        out << "\"" << value << "\"";
    }
};

struct BoolValue : JsonValue {
    bool value;

    BoolValue(bool x) : value(x) {
    }

    void print(std::ostream& out) override {
        out << (value ? "true" : "false");
    }
};

struct NullValue : JsonValue {
    NullValue() {
    }

    void print(std::ostream& out) override {
        out << "null";
    }
};

struct ArrayValue : JsonValue {
    JsonValue* values[16];
    unsigned size;

    ArrayValue() : size(0) {
    }

    void add(JsonValue* value) {
        if (size < 16) {
            values[size++] = value;
        }
    }
    void print(std::ostream& out) override {
        out << "[";
        for (int i = 0; i < size; i++) {
            values[i]->print(out);
            if (i != size - 1) {
                out << ", ";
            }
        }
        out << "]";
    }
};

struct ObjectValue : JsonValue {
    struct Pair {
        char name[256];
        JsonValue* value;
    };
    Pair values[16];
    unsigned size;

    ObjectValue() : size(0) {
    }

    void add(const char* name, JsonValue* value) {
        strcpy(values[size].name, name);
        values[size].value = value;
        size++;
    }
    void print(std::ostream& out) override {
        out << "{\n";
        for (int i = 0; i < size; i++) {
            out << "\"" << values[i].name << "\": ";
            values[i].value->print(out);
            if (i != size - 1) {
                out << ",";
            }
            out << "\n";
        }
        out << "}\n";
    }
};



int main() {
    auto array_numbers = new ArrayValue();
    array_numbers->add(new NumberValue(5));
    array_numbers->add(new NumberValue(10));
    array_numbers->add(new NumberValue(15));

    auto array_strings = new ArrayValue();
    array_strings->add(new StringValue("abc"));
    array_strings->add(new StringValue("def"));
    array_strings->add(new StringValue("ghi"));

    auto subobject = new ObjectValue();
    subobject->add("email", new StringValue("t@gmail.com"));
    subobject->add("name", new StringValue("T"));
    subobject->add("online", new BoolValue(true));

    auto object = new ObjectValue();
    object->add("n", new NullValue());
    object->add("array_numbers", array_numbers);
    object->add("array_strings", array_strings);
    object->add("info", subobject);

    object->print(std::cout);
}

JsonValue::~JsonValue() {
}

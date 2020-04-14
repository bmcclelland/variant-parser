#include "parse_input.h"

InputRollback::InputRollback(Input& input, size_t rollback)
    : _input(input)
    , _rollback(rollback)
    , _canceled(false)
{}

InputRollback::~InputRollback() {
    if (!_canceled) {
        _input._pos = _rollback;
    }
}

void InputRollback::cancel() {
    _canceled = true;
}

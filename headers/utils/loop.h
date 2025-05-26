//
// Created by mrnotgramatika on 5/26/25.
//

#ifndef LOOP_H
#define LOOP_H

constexpr void loop(int interations, auto func = []{}) {
    for (int i = 0; i < interations; i++)
        func();
}

#endif //LOOP_H

#ifndef __STUDENT_H_
#define __STUDENT_H_

// ไลบรารีที่จำเป็นสำหรับการแก้ปัญหา
#include "vector.h"
#include <map>
#include <algorithm>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
    // ฟังก์ชันนี้จะลบข้อมูลซ้ำออกจาก vector โดยเก็บไว้แค่ตัวที่อยู่ใกล้ begin() มากที่สุด
    
    // ขั้นตอนที่ 1: แปลง iterator เป็น index เพื่อความสะดวกในการจัดการ
    std::map<T, int> first_occurrence; // เก็บ index ของการพบครั้งแรกของแต่ละค่า
    std::vector<int> indices; // เก็บ index ทั้งหมดที่เราต้องพิจารณา
    
    // แปลง iterator เป็น index และเก็บไว้ในรายการ
    for (auto it : itrs) {
        int index = it - begin(); // คำนวณ index จาก iterator
        indices.push_back(index);
    }
    
    // ขั้นตอนที่ 2: หาข้อมูลซ้ำโดยใช้ map เพื่อติดตามการพบครั้งแรก
    std::vector<int> to_remove; // เก็บ index ของข้อมูลที่ต้องลบ
    
    for (int idx : indices) {
        T value = mData[idx]; // ค่าข้อมูลที่ตำแหน่ง idx
        
        if (first_occurrence.find(value) == first_occurrence.end()) {
            // ยังไม่เคยพบค่านี้มาก่อน - บันทึกเป็นการพบครั้งแรก
            first_occurrence[value] = idx;
        } else {
            // พบค่านี้แล้ว - ต้องลบตัวที่พบทีหลัง
            int first_idx = first_occurrence[value];
            if (idx < first_idx) {
                // ถ้า index ปัจจุบันเล็กกว่า (ใกล้ begin() มากกว่า) ให้ลบตัวเก่าแทน
                to_remove.push_back(first_idx);
                first_occurrence[value] = idx; // อัพเดต index ของการพบครั้งแรก
            } else {
                // ถ้า index ปัจจุบันใหญ่กว่า ให้ลบตัวปัจจุบัน
                to_remove.push_back(idx);
            }
        }
    }
    
    // ขั้นตอนที่ 3: เรียง index ที่ต้องลบจากมากไปน้อย
    // เหตุผล: การลบจากหลังไปหน้าจะไม่ทำให้ index ข้างหน้าเปลี่ยนแปลง
    std::sort(to_remove.begin(), to_remove.end(), std::greater<int>());
    
    // ขั้นตอนที่ 4: ลบข้อมูลทีละตัวโดยเริ่มจากหลังสุด
    for (int idx : to_remove) {
        erase(begin() + idx); // ใช้ฟังก์ชัน erase ของ vector เพื่อลบข้อมูล
    }
    
    // หมายเหตุ: ความซับซ้อนของอัลกอริทึมคือ O(n log n + k) 
    // โดยที่ n คือจำนวน iterator และ k คือจำนวนข้อมูลที่ต้องลบ
}

#endif 

/*
a 0 5
a 1 5
a 2 10
a 3 5
a 4 10
p
u 4 0 2 3 4
p
a 2 3
p
u 4 2 3 1 0
p
q
*/
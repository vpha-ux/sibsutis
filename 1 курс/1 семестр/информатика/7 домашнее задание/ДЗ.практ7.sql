CREATE TABLE `organisations`(
    `id` INTEGER PRIMARY KEY,
    `billing_address` TEXT,
    `address` TEXT,
    `email` TEXT,
    `phone_number` TEXT,
    `note` TEXT
);

CREATE TABLE `employees`(
    `id` INTEGER PRIMARY KEY,
    `full_name` TEXT,
    `education_level` TEXT,
    `address` TEXT,
    `phone_number` TEXT,
    `email` TEXT,
    `note` TEXT
);

CREATE TABLE `delivery_choices`(
    `id` INTEGER PRIMARY KEY,
    `name` TEXT,
    `note` TEXT
);

CREATE TABLE `suppliers`(
    `id` INTEGER PRIMARY KEY,
    `name` TEXT,
    `billing_address` TEXT,
    `address` TEXT,
    `phone_number` TEXT,
    `email` TEXT,
    `note` TEXT
);

CREATE TABLE `types`(
    `id` INTEGER PRIMARY KEY,
    `name` TEXT,
    `note` TEXT
);

CREATE TABLE `measure_units`(
    `id` INTEGER PRIMARY KEY,
    `name` TEXT
);

CREATE TABLE `clients`(
    `id` INTEGER PRIMARY KEY,
    `full_name` TEXT,
    `address` TEXT,
    `phone_number` TEXT,
    `email` TEXT,
    `note` TEXT
);

CREATE TABLE `goods`(
    `id` INTEGER PRIMARY KEY,
    `name` TEXT,
    `supplier_id` INTEGER,
    `type_id` INTEGER,
    `measure_unit_id` INTEGER,
    `price` REAL,
    `status` TEXT,
    FOREIGN KEY (`supplier_id`) REFERENCES `suppliers`(`id`),
    FOREIGN KEY (`type_id`) REFERENCES `types`(`id`),
    FOREIGN KEY (`measure_unit_id`) REFERENCES `measure_units`(`id`)
);

CREATE TABLE `orders`(
    `id` INTEGER PRIMARY KEY,
    `organisation_id` INTEGER,
    `good_id` INTEGER,
    `employee_id` INTEGER,
    `client_id` INTEGER,
    `delivery_choice_id` INTEGER,
    `date` TEXT,
    `price` REAL,
    `discount` REAL,
    `delivery_price` REAL,
    FOREIGN KEY (`organisation_id`) REFERENCES `organisations`(`id`),
    FOREIGN KEY (`good_id`) REFERENCES `goods`(`id`),
    FOREIGN KEY (`employee_id`) REFERENCES `employees`(`id`),
    FOREIGN KEY (`client_id`) REFERENCES `clients`(`id`),
    FOREIGN KEY (`delivery_choice_id`) REFERENCES `delivery_choices`(`id`)
);